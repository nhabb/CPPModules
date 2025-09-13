#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",72,45),target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)  : AForm("ShrubberyCreationForm",72,45), target(target) {}

void ShrubberyCreationForm::executeAction() const 
{
    std::ofstream ofs((target + "_shrubbery").c_str());
    ofs << "       ###\n"
           "      #o###\n"
           "    #####o###\n"
           "   #o#\\#|#/###\n"
           "    ###\\|/#o#\n"
           "     # }|{  #\n"
           "       }|{\n";
    ofs.close();
}


