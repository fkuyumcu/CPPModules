#include "ClapTrap.hpp"

int main()
{
    ClapTrap cp("Furkan");
    

    //attack test
    cp.attack("Enemy");
    cp.attack("Monster");

    //repair test
    cp.beRepaired(5);
    cp.beRepaired(3);

    //damage test
    cp.takeDamage(8);
    cp.takeDamage(15); 

    //no energy test
    cp.attack("Target"); 
    cp.beRepaired(5);
    cp.takeDamage(5);
    
    ClapTrap cp2("Tester");

    
    ClapTrap cp3(cp2);
    ClapTrap cp4("Original");
    cp4 = cp3;
    
    return 0;
}