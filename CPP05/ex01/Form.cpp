#include "Form.hpp"

Form::Form() : name("def") ,isSigned(false),gradeToSign(150) ,gradeToExecute(150){}
Form::~Form(){}

Form &Form::operator=(const Form &obj)
{
    if (this != &obj)
    {
        *this = obj;
    }
    return *this;
}

Form::Form(const Form &obj) : name(obj.name) ,isSigned(obj.isSigned),gradeToSign(obj.gradeToSign) ,gradeToExecute(obj.gradeToExecute){}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name) ,isSigned(false),gradeToSign(gradeToSign) ,gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
bool Form::getIsSigned() const
{
    return isSigned;
}

const std::string Form::getName() const
{
    return this->name;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

std::ostream &operator<<(std::ostream &out, const Form &b)
{
    out<< "form name: "<<b.getName() <<"| grade to sign: "<< b.getGradeToSign() <<"| grade to execute: " <<b.getGradeToExecute()<< "| signature status: " <<b.getIsSigned()<<std::endl;
    return out;
}

void Form::beSigned(Bureaucrat ber)
{
    if (ber.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    if (ber.getGrade() >= gradeToSign && ber.getGrade() <= gradeToExecute)
        isSigned = true;
}

// void Form::signForm(Bureaucrat ber)
// {
//     try
//     {
//         beSigned(ber);
//     }
//     catch(std::exception  &e)
//     {
//         std::cout<< ber.getName()<<" couldn't sign "<< getName() << " becuase "<< e.what()<<std::endl;
//         return ;
//     }
//     std::cout<<ber.getName() <<" signed "<<getName()<<std::endl;
// }