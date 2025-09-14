#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class Bureaucrat;

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
    AForm(const AForm &obj);
    AForm &operator=(const AForm &obj);
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &ber);
    void execute(const Bureaucrat &executor) const;

    virtual void executeAction() const = 0;

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() { return "Grade too low"; }
    };

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() { return "Grade too high"; }
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw() { return "Form is not signed"; }
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &b);

#endif
