
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>


class FragTrap : public ClapTrap
{
    public:
    //orthadox canonical form
        FragTrap();
    	FragTrap(std::string Name);
    	FragTrap(const FragTrap &f);
    	FragTrap& operator=(const FragTrap &f);
    	~FragTrap();

        void attack(const std::string& target);
        void highFivesGuys(void);
};






#endif
