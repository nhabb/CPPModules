#include "Harl.hpp"

void Harl::debug()
{
    std::cout<<"[DEBUG]"<<std::endl<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
             << "ketchup burger. I really do!"<<std::endl;
}

void Harl::error()
{
    std::cout<<"[ERROR]"<<std::endl<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::info()
{
    std::cout<<"[INFO]"<<std::endl<<"I cannot believe adding extra bacon costs more money. You didn't put"
                <<" enough bacon in my burger! If you did, I wouldn't be asking for more!"<<std::endl;

}

void Harl::warning()
{
    std::cout<<"[WARNING]"<<std::endl<<"I think I deserve to have some extra bacon for free. I've been coming for"
                <<"years, whereas you started working here just last month."<<std::endl;
}

void Harl::complain(std::string level)
{

    int levelNumber;
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    if (level == "WARNING")
        levelNumber = 1;
    if (level == "ERROR")
        levelNumber = 2;
    if (level == "DEBUG")
        levelNumber = 3;
    if (level == "INFO")
        levelNumber = 4;
    switch (levelNumber)
    {
    case 1:
        warning();
        // fall through
    case 2:
        error();
        // fall through
    case 3:
        debug();
        // fall through
    case 4:
        info();
    default:
        break;
    }

}