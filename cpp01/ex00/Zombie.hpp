#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class  Zombie
{
    private:
        std::string name;
        
    public:
    
    void announce(void);
    
    //Stack and Heap Functions
    Zombie* newZombie(std::string name);
    void randomChump(std::string name);
    
    //Constructor and Destructor
    Zombie(std::string name);
    ~Zombie();
};





#endif