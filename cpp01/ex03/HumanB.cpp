#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(const std::string name):name(name){
    this->wpn = NULL;
}

HumanB::~HumanB(){
    
}


Weapon *HumanB::getWeapon(void)
{
    return (this->wpn);
}

void HumanB::setWeapon(Weapon &wpn)
{
    this->wpn = &wpn;
}

void HumanB::attack()
{
    if (wpn)
    std::cout << name << " attacks with their " << wpn->getType() << std::endl;
    else
    std::cout << name << " has no weapon to attack with " << std::endl;
}