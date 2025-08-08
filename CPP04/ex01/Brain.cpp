#include "Brain.hpp"

Brain::Brain()
{
    std::cout<<"Brain created"<<std::endl;
}
Brain::~Brain()
{
    std::cout<<"Brain destroyed"<<std::endl;
}
Brain::Brain(const Brain &obj)
{
    *this = obj;
}
Brain &Brain::operator=(const Brain &obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = obj.ideas[i];
        }
    }
    return *this;
}