                     
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string Name);
        ScavTrap(const ScavTrap &f);
        ScavTrap& operator=(const ScavTrap &f);
        ~ScavTrap();

        void attack(const std::string& target);
        void guardGate();
};








#endif
