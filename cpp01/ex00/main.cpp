#include "Zombie.hpp"

int main(void)
{

    Zombie *HeapZombie = new Zombie("HeapZombie");
    HeapZombie->announce();

    delete HeapZombie;

    Zombie StackZombie("StackZombie");
    StackZombie.randomChump("StackZombie");
    StackZombie.announce();
}
