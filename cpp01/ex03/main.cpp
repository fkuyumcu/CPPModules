#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
int main(void)
{

Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.attack();
club.setType("some other type of club");
jim.attack();
}