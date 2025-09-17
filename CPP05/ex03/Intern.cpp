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

static AForm* createShrub(const std::string& target) 
{
    return new ShrubberyCreationForm(target); 
}
static AForm* createRobo(const std::string& target) 
{ 
    return new RobotomyRequestForm(target); 
}
static AForm* createPardon(const std::string& target) 
{
    return new PresidentialPardonForm(target); 
}

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*creators[3])(const std::string&) = { createShrub, createRobo, createPardon };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern could not find the form: " << formName << std::endl;
    return NULL;
}

