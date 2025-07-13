#include "ClapTrap.hpp"

int main()
{
    ClapTrap cp("Furkan");
    
    std::cout << "=== Basic Attack Test ===" << std::endl;
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
    
    std::cout << "\n=== Energy Depletion Test ===" << std::endl;
    ClapTrap cp2("Tester");
    
    for(int i = 0; i < 10; i++)
        cp2.attack("Target");
    
    cp2.attack("Target");
    cp2.beRepaired(1);
    
    std::cout << "\n=== Copy Test ===" << std::endl;
    ClapTrap cp3(cp2);
    ClapTrap cp4("Original");
    cp4 = cp3;
    
    return 0;
}