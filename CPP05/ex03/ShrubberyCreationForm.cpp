#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
 std::ofstream out((target + "_shrubbery").c_str());
    if (!out)
        throw std::runtime_error("Could not open file");
   out << "      *\n"
       "     ***\n"
       "    *****\n"
       "   *******\n"
       "  *********\n"
       "     ***\n"
       "     ***\n";
}
