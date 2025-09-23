#include "Data.hpp"

Data::Data() : id(0), name(""), value(0.0) {}

Data::Data(int i, const std::string &n, double v) : id(i), name(n), value(v) {}
