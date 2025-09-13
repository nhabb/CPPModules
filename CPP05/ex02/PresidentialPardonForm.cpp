#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25,5),target("default"){}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",25,5),target(target){}

void PresidentialPardonForm::executeAction()
{
    std::cout<< this->target <<" has been pradoned by Zaphod Beeblebrox."<<std::endl;
}