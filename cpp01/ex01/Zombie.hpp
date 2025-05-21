#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
    Zombie();
    ~Zombie();
    
    
    std::string name;
    void announce(void);
    private:
    
    
};

Zombie *zombieHorde(int N, std::string name);


#endif