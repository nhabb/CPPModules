#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
#include <iostream>

class GradeTooHighException : public std::exception
{
    virtual const char * what() const throw()
    {
        return "Grade too high";
    }
};

class GradeTooLowException : public std::exception
{
    virtual const char * what() const throw()
    {
        return "Grade too low";
    }
};
class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:

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