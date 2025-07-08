#include "Zombie.hpp"

int main(void)
{
    Zombie* zomb;
    zomb = zombieHorde(5, "furkan");
    zomb[0].announce();
    zomb[1].announce();
    zomb[3].announce();

    delete[] zomb;
}