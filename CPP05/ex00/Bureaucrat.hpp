#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
#include <iostream>

class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what() const throw()
                {
                    return "Grade too high";
                }
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw()
                {
                    return "Grade too low";
                }
        };

        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        
        Bureaucrat(std::string name,int grade);
        int getGrade() const;
        std::string getName() const;
        Bureaucrat operator++(int);
        Bureaucrat operator--(int);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif