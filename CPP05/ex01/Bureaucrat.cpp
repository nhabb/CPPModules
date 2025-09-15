#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("def"), grade(0){}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    name = obj.name;
    grade = obj.grade;
}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        *this = obj;
    }
    return *this;
}

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
    if (grade < 1)
        throw GradeTooHighException();
    grade--;
    return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
    if (grade > 150)
        throw GradeTooLowException();
    grade++;
    return *this;
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out<< b.getName()<<", bureaucrat grade "<<b.getGrade();
    return out;
}

void Bureaucrat::signForm(Form &form) const
{
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}