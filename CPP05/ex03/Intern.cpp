#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &obj)
{
    (void)obj;
}

Intern &Intern::operator=(const Intern &obj)
{
    (void)obj;
    return (*this);
}

int Intern::getFormType(const std::string& formName) const
{
    if (formName == "shrubbery creation")
        return 0;
    else if (formName == "robotomy request")
        return 1;
    else if (formName == "presidential pardon")
        return 2;
    else
        return -1;
}

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
    int formType = getFormType(formName);
    
    switch (formType)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern could not find the form: " << formName << std::endl;
            return NULL;
    }
}