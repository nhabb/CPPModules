#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name,int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    this->name = name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}
std::string Bureaucrat::getName() const
{
    return this->name;
}

Bureaucrat Bureaucrat::operator++(int)
{
    grade--;
    if (grade < 1)
        throw GradeTooHighException();
    return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
    grade++;
    if (grade > 150)
        throw GradeTooLowException();
    return *this;
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out<< b.getName()<<", bureaucrat grade "<<b.getGrade();
    return out;
}