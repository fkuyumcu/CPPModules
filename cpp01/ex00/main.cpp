#include "Zombie.hpp"

int main(void)
{

    Zombie *HeapZombie = newZombie("heapZombie");
    HeapZombie->announce();

    delete HeapZombie;

    randomChump("StackZombie"); 
}
