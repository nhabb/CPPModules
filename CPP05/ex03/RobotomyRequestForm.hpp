#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;

public:
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();
    void executeAction() const;
};

#endif
