#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name)
{
    std::cout << "Constructor Called" << std::endl;
    this->Name = Name;
    this->AttackDamage = 0;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
}


ClapTrap::~ClapTrap()
{
    std::cout << "Destructor Called" << std::endl;


}

void ClapTrap::attack(const std::string& target)
{
    if(this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->Name << " can't do anything!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        std::cout << "ClapTrap " << this->Name << " heals itself" << std::endl;
        this->EnergyPoints--;
        this->HitPoints += amount;
    }
    else
        std::cout << "ClapTrap " << this->Name << " can't do anything!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->HitPoints == 0)
    {
        std::cout << "ClapTrap " << this->Name << " died already." << std::endl;
    }
    else 
    {
        if(this->HitPoints >= amount)
            this->HitPoints -= amount;
        else
            this->HitPoints = 0;
        std::cout << "ClapTrap " << this->Name << " takes " << amount << " damage!" << std::endl;
    }
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return *this;
}




