#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>

// Forward declare Bureaucrat to avoid circular include
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

    // ✅ Checks signed + grade, then calls executeAction
    void execute(const Bureaucrat &executor) const;

    // ✅ Pure virtual function: each derived form must implement its action
    virtual void executeAction() const = 0;

    // Optional pure virtual signForm (if you want Bureaucrat to sign this way)
    virtual void signForm(const Bureaucrat &ber) = 0;

    // Exceptions
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
