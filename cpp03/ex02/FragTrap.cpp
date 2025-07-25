#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Default Constructor Called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    std::cout << "FragTrap Constructor Called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    this->Name = Name;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap(f)
{
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
    *this = f;
}

FragTrap& FragTrap::operator=(const FragTrap &f)
{
    std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
    if (this != &f)
    {
        ClapTrap::operator=(f);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if(this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    else
        std::cout << "FragTrap " << this->Name << " can't do anything" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->Name << " says: High five" << std::endl;
}