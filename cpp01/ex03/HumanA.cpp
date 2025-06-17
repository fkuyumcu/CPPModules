#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &wpn)
    : name(name), wpn(wpn)//constructor initializer 
{


}

HumanA::~HumanA()
{


}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << wpn.getType() << std::endl;
}
