#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:

        Form();
        ~Form();
        Form &operator=(const Form &obj);
        Form(const Form &obj);

        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        // void signForm(Bureaucrat ber);
        void beSigned(Bureaucrat ber);
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw()
                {
                    return "Grade too low";
                }
        };
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what() const throw()
                {
                    return "Grade too high";
                }
        };
};

std::ostream &operator<<(std::ostream &out, const Form &b);


#endif