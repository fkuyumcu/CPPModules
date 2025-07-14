
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap
{
    public:
        ClapTrap();
    	ClapTrap(std::string Name);
    	ClapTrap(const ClapTrap &f);
    	ClapTrap& operator=(const ClapTrap &f);
    	~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    protected:
        std::string Name;
        size_t HitPoints;
        size_t EnergyPoints;
        size_t AttackDamage;



};






#endif
