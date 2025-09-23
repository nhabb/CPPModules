#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
	// Prevent instantiation/copy (utility class)
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();

public:
	// Single public static API as required by the subject
	static void convert(const std::string &literal);
};

#endif // SCALARCONVERTER_HPP