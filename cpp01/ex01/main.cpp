#include "Zombie.hpp"

int main(void)
{
    Zombie* zomb;
    zomb = zombieHorde(3, "furkan");
    zomb[0].announce();
    delete[] zomb;
}