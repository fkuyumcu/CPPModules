#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor Called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
}

Brain::Brain(const Brain &b)
{
    std::cout << "Brain Copy Constructor Called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = b.ideas[i];
}

Brain& Brain::operator=(const Brain &b)
{
    std::cout << "Brain Copy Assignment Called" << std::endl;
    if (this != &b)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = b.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}




