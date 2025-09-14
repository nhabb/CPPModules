#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors & Destructor
AForm::AForm()
    : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &obj)
    : name(obj.name), isSigned(obj.isSigned),
      gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) {}

AForm &AForm::operator=(const AForm &obj)
{
    if (this != &obj)
        isSigned = obj.isSigned;
    return *this;
}

AForm::~AForm() {}

// Getters
std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

// Member Functions
void AForm::beSigned(const Bureaucrat &ber)
{
    if (ber.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

// Stream operator
std::ostream &operator<<(std::ostream &out, const AForm &b)
{
    out << "Form: " << b.getName()
        << " | Signed: " << (b.getIsSigned() ? "yes" : "no")
        << " | Grade to sign: " << b.getGradeToSign()
        << " | Grade to execute: " << b.getGradeToExecute();
    return out;
}
