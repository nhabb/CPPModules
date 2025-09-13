#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotmyRequestForm",145,137), target("default"){}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotmyRequestForm",145,137), target(target){}

void RobotomyRequestForm::executeAction()
{
    std::cout<<"BRRRRRRRRRRRRRRRRRRRSZZZZZZZZZZZZZRRRRRRRRRRRRRRRRRRZZZZ"<<std::endl;

    srand(time(0));
    if (std::rand() % 2)
    {
        std::cout<< target << " has been robotomized"<<std::endl;
    }
    else
    {
        std::cout<< target <<"'s robotomy failed"<<std::endl;
    }
}