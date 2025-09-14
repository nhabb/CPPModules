#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern
{
    private:
        int getFormType(const std::string& formName) const;

    public:
        Intern();
        ~Intern();
        Intern(const Intern &obj);
        Intern &operator=(const Intern &obj);
        AForm* makeForm(const std::string formName, const std::string target);
};

#endif