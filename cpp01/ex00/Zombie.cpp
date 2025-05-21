#include "Zombie.hpp"


Zombie::Zombie(std::string name) : name(name)
{

}

Zombie::~Zombie()
{
    std::cout << this->name << " destroyed." << std::endl;
}

Zombie *Zombie::newZombie(std::string name)
{
    return new Zombie(name);
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
