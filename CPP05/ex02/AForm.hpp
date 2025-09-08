#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        AForm();
        virtual ~AForm();
        AForm &operator=(const AForm &obj);
        AForm(const AForm &obj);

        AForm(const std::string& name, int gradeToSign, int gradeToExecute);

        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        virtual void signForm(Bureaucrat ber) = 0;
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

std::ostream &operator<<(std::ostream &out, const AForm &b);

#endif
