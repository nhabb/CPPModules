#include "AForm.hpp"

AForm::AForm() : name("def") ,isSigned(false),gradeToSign(150) ,gradeToExecute(150){}
AForm::~AForm(){}

AForm &AForm::operator=(const AForm &obj)
{
    if (this != &obj)
    {
        *this = obj;
    }
    return *this;
}

AForm::AForm(const AForm &obj) : name(obj.name) ,isSigned(obj.isSigned),gradeToSign(obj.gradeToSign) ,gradeToExecute(obj.gradeToExecute){}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name) ,isSigned(false),gradeToSign(gradeToSign) ,gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
bool AForm::getIsSigned() const
{
    return isSigned;
}

const std::string AForm::getName() const
{
    return this->name;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

std::ostream &operator<<(std::ostream &out, const AForm &b)
{
    out<< "form name: "<<b.getName() <<"| grade to sign: "<< b.getGradeToSign() <<"| grade to execute: " <<b.getGradeToExecute()<< "| signature status: " <<b.getIsSigned()<<std::endl;
    return out;
}

void AForm::beSigned(Bureaucrat ber)
{
    if (ber.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    if (ber.getGrade() >= gradeToSign && ber.getGrade() <= gradeToExecute)
        isSigned = true;
}

void AForm::signForm(Bureaucrat ber)
{
    try
    {
        beSigned(ber);
    }
    catch(std::exception  &e)
    {
        std::cout<< ber.getName()<<" couldn't sign "<< getName() << " becuase "<< e.what()<<std::endl;
        return ;
    }
    std::cout<<ber.getName() <<" signed "<<getName()<<std::endl;
}