#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::~AForm() {}

AForm::AForm(const AForm &obj)
    : name(obj.name), isSigned(obj.isSigned),
      gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) {}

AForm &AForm::operator=(const AForm &obj) {
    if (this != &obj)
        this->isSigned = obj.isSigned;
    return *this;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
 std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat &ber) {
    if (ber.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &b) {
    out << b.getName() << " (sign grade " << b.getGradeToSign()
        << ", exec grade " << b.getGradeToExecute()
        << ", signed: " << (b.getIsSigned() ? "yes" : "no") << ")";
    return out;
}
