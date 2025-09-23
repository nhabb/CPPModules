#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cctype>

namespace {

// Trim helper
static std::string trim(const std::string &s) {
    std::string::size_type start = 0; while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) ++start;
    std::string::size_type end = s.size(); while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) --end;
    return s.substr(start, end - start);
}

// Check pseudo literals
static bool isPseudoFloat(const std::string &s) {
    return (s == "nanf" || s == "+inff" || s == "-inff");
}

static bool isPseudoDouble(const std::string &s) {
    return (s == "nan" || s == "+inf" || s == "-inf");
}

// Detection helpers
static bool isCharLiteral(const std::string &s) {
    if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]))) return true;
    // handle quoted: 'c'
    return (s.size() == 3 && s[0] == '\'' && s[2] == '\'' && !std::isdigit(static_cast<unsigned char>(s[1])));
}

static bool isIntLiteral(const std::string &s) {
    if (s.empty()) return false;
    std::size_t i = (s[0] == '+' || s[0] == '-') ? 1u : 0u;
    if (i == s.size()) return false;
    for (; i < s.size(); ++i) if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    return true;
}

static bool isFloatLiteral(const std::string &s) {
    if (isPseudoFloat(s)) return true;
    if (s.size() < 2 || s[s.size() - 1] != 'f') return false;
    std::string core = s.substr(0, s.size() - 1);
    bool hasDot = false;
    std::size_t i = (core[0] == '+' || core[0] == '-') ? 1u : 0u;
    if (i == core.size()) return false;
    for (; i < core.size(); ++i) {
        if (core[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(static_cast<unsigned char>(core[i]))) {
            return false;
        }
    }
    return hasDot; // must contain a dot
}

static bool isDoubleLiteral(const std::string &s) {
    if (isPseudoDouble(s)) return true;
    bool hasDot = false;
    if (s.empty()) return false;
    std::size_t i = (s[0] == '+' || s[0] == '-') ? 1u : 0u;
    if (i == s.size()) return false;
    for (; i < s.size(); ++i) {
        if (s[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(static_cast<unsigned char>(s[i]))) {
            return false;
        }
    }
    return hasDot; // must contain a dot
}

// Printing helpers
// NaN/Inf helpers compatible with C++98
static bool isNanLD(long double v) { return v != v; }
static bool isInfLD(long double v) {
    long double inf = std::numeric_limits<long double>::infinity();
    return v == inf || v == -inf;
}
static bool isNanF(float v) { return v != v; }
static bool isInfF(float v) { float inf = std::numeric_limits<float>::infinity(); return v == inf || v == -inf; }
static bool isNanD(double v) { return v != v; }
static bool isInfD(double v) { double inf = std::numeric_limits<double>::infinity(); return v == inf || v == -inf; }

static void printChar(long double v, bool impossible) {
    if (impossible || v < std::numeric_limits<char>::min() || v > std::numeric_limits<char>::max() || isNanLD(v)) {
        std::cout << "char: impossible\n";
        return;
    }
    char c = static_cast<char>(v);
    std::cout << (std::isprint(static_cast<unsigned char>(c)) ? std::string("char: '") + c + "'\n" : std::string("char: Non displayable\n"));
}

static void printInt(long double v, bool impossible) {
    if (impossible || v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max() || isNanLD(v) || isInfLD(v)) {
        std::cout << "int: impossible\n";
        return;
    }
    std::cout << "int: " << static_cast<int>(v) << "\n";
}

static std::string formatNumber(double d) {
    std::stringstream ss;
    ss << std::setprecision(15) << d; // high precision to capture value
    std::string str = ss.str();
    // Ensure decimal point and trim trailing zeros
    std::string::size_type pos = str.find('.');
    if (pos == std::string::npos) {
        // integer, add .0
        return str + ".0";
    }
    // trim trailing zeros
    std::string::size_type end = str.size();
    while (end > pos + 1 && str[end - 1] == '0') --end;
    if (end > 0 && str[end - 1] == '.') ++end; // keep one digit after '.' by adding one back? we'll ensure at least one digit below
    std::string out = str.substr(0, end);
    // Ensure at least one digit after '.'
    if (out[out.size() - 1] == '.') out += '0';
    return out;
}

static void printFloat(long double v, bool isPseudo, const std::string &pseudoStr) {
    if (isPseudo) {
        std::cout << "float: " << (pseudoStr == "nan" ? "nanf" : pseudoStr + "f") << "\n";
        return;
    }
    float f = static_cast<float>(v);
    if (isNanF(f)) { std::cout << "float: nanf\n"; return; }
    if (isInfF(f)) { std::cout << (f > 0 ? "float: +inff\n" : "float: -inff\n"); return; }
    std::cout << "float: " << formatNumber(static_cast<double>(f)) << 'f' << "\n";
}

static void printDouble(long double v, bool isPseudo, const std::string &pseudoStr) {
    if (isPseudo) {
        std::cout << "double: " << pseudoStr << "\n";
        return;
    }
    double d = static_cast<double>(v);
    if (isNanD(d)) { std::cout << "double: nan\n"; return; }
    if (isInfD(d)) { std::cout << (d > 0 ? "double: +inf\n" : "double: -inf\n"); return; }
    std::cout << "double: " << formatNumber(d) << "\n";
}

// Parse using stringstream; returns success and value via reference
static bool sstreamToLongDouble(const std::string &s, long double &out) {
    std::stringstream ss(s);
    ss >> out;
    return ss && ss.eof();
}

} // namespace

// Private special member functions disabled
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &input) {
    const std::string s = trim(input);

    bool pseudo = isPseudoFloat(s) || isPseudoDouble(s);
    std::string pseudoStr = isPseudoFloat(s) ? s.substr(0, s.size() - 1) : (isPseudoDouble(s) ? s : "");

    long double value = 0.0L;
    bool intLit = false, floatLit = false, doubleLit = false, charLit = false;

    if (pseudo) {
        // value doesn't matter for pseudo, but set to NaN for safety
        value = std::numeric_limits<long double>::quiet_NaN();
    } else if ((charLit = isCharLiteral(s))) {
        char c = (s.size() == 1) ? s[0] : s[1];
        value = static_cast<unsigned char>(c);
    } else if ((intLit = isIntLiteral(s))) {
        // use stringstream to parse
        long long tmp = 0;
        std::stringstream ss(s);
        ss >> tmp;
        if (!ss || !ss.eof()) {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
        if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max()) {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
        value = static_cast<long double>(static_cast<int>(tmp));
    } else if ((floatLit = isFloatLiteral(s))) {
        std::string core = s.substr(0, s.size() - 1);
        if (!sstreamToLongDouble(core, value)) {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
    } else if ((doubleLit = isDoubleLiteral(s))) {
        if (!sstreamToLongDouble(s, value)) {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
    } else {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    // Output
    printChar(value, pseudo);
    printInt(value, pseudo);
    printFloat(value, pseudo, pseudoStr);
    printDouble(value, pseudo, pseudoStr);
}