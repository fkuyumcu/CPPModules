#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default Constructor Called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    std::cout << "ScavTrap Constructor Called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    this->Name = Name;
}

ScavTrap::ScavTrap(const ScavTrap &f) : ClapTrap(f)
{
    std::cout << "ScavTrap Copy Constructor Called" << std::endl;
    *this = f;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &f)
{
    std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
    if (this != &f)
    {
        ClapTrap::operator=(f);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    else
        std::cout << "ScavTrap " << this->Name << " can't do anything!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode." << std::endl;
}