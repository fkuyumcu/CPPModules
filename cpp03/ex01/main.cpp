#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap Tests ===" << std::endl;
    ClapTrap cp("Furkan");
    
    std::cout << "\n=== Basic Attack Test ===" << std::endl;
    cp.attack("Enemy");
    cp.attack("Monster");
    
    std::cout << "\n=== Repair Test ===" << std::endl;
    cp.beRepaired(5);
    cp.beRepaired(3);
    
    std::cout << "\n=== Damage Test ===" << std::endl;
    cp.takeDamage(8);
    cp.takeDamage(15); 
    
    std::cout << "\n=== No Energy/HP Test ===" << std::endl;
    cp.attack("Target"); 
    cp.beRepaired(5);
    cp.takeDamage(5);
    
    std::cout << "\n=====================" << std::endl;
    std::cout << "=== ScavTrap Tests ===" << std::endl;
    std::cout << "=====================" << std::endl;
    
    std::cout << "\n=== ScavTrap Construction Test ===" << std::endl;
    ScavTrap st("Robot");
    
    std::cout << "\n=== ScavTrap Attack Test ===" << std::endl;
    st.attack("Enemy");
    st.attack("Monster");
    
    std::cout << "\n=== ScavTrap Guard Gate Test ===" << std::endl;
    st.guardGate();
    
    std::cout << "\n=== ScavTrap Repair Test ===" << std::endl;
    st.beRepaired(10);
    
    std::cout << "\n=== ScavTrap Damage Test ===" << std::endl;
    st.takeDamage(30);
    st.takeDamage(50);
    
    std::cout << "\n=== ScavTrap Copy Test ===" << std::endl;
    ScavTrap st2(st);
    ScavTrap st3("Original");
    st3 = st2;
    
    std::cout << "\n=== Default Constructor Test ===" << std::endl;
    ScavTrap st4;
    st4.attack("Target");
    st4.guardGate();
    
    std::cout << "\n=== Destruction Order Test ===" << std::endl;
    // Objects will be destroyed in reverse order of construction
    
    return 0;
}