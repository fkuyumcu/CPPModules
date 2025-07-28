#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain()
{
    std::cout << BOLD_BLUE << "Brain Default Constructor Called" << RESET << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
}

Brain::Brain(const Brain &b)
{
    std::cout << BOLD_BLUE << "Brain Copy Constructor Called" << RESET << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = b.ideas[i];
}

Brain& Brain::operator=(const Brain &b)
{
    std::cout << BOLD_BLUE << "Brain Copy Assignment Called" << RESET << std::endl;
    if (this != &b)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = b.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << BOLD_RED << "Brain Destructor Called" << RESET << std::endl;
}




