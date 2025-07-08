#include "Zombie.hpp"

int main(void)
{
    Zombie *HeapZombie = newZombie("furkan");
    HeapZombie->announce();

    delete HeapZombie;

    randomChump("kuyumcu"); 
}
