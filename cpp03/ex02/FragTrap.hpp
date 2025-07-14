
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>


class FragTrap
{
    public:
        FragTrap();
    	FragTrap(std::string Name);
    	FragTrap(const FragTrap &f);
    	FragTrap& operator=(const FragTrap &f);
    	~FragTrap();

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
