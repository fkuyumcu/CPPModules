#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    
    //default constructor
    ScavTrap st4;
    

    //fragtrap tests
    
    FragTrap ft("Frag");
    
    ft.attack("Enemy");
    ft.attack("Monster");
    
    //highfives
    ft.highFivesGuys();
    //healing
    ft.beRepaired(15);
    //takedmg
    ft.takeDamage(40);
    ft.takeDamage(70);
    
    //copy test
    FragTrap ft2(ft);
    FragTrap ft3("Original");
    ft3 = ft2;
    ft3.highFivesGuys();
    
    return 0;
}