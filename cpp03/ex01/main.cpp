#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap cp("Furkan");
    

    //attack test
    cp.attack("st2");
    cp.attack("st3");

    //repair test
    cp.beRepaired(5);
    cp.beRepaired(3);

    //damage test
    cp.takeDamage(8);
    cp.takeDamage(15); 

    //no energy test
    cp.attack("target"); 
    cp.beRepaired(5);
    cp.takeDamage(5);
    

    //scavtrap tests
    
    ScavTrap st("Robot");
    
    //attack
    st.attack("st2");
    st.attack("st3");

    //guardgate test
    st.guardGate();

    //repairtest
    st.beRepaired(10);

    //take dmg
    st.takeDamage(30);
    st.takeDamage(50);
    

    
    return 0;
}