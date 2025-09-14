#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat &operator=(const Bureaucrat &obj);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void increment();
    void decrement();

    void signForm(AForm &form) const;
    void executeForm(const AForm &form) const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() { return "Bureaucrat grade too high"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() { return "Bureaucrat grade too low"; }
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
