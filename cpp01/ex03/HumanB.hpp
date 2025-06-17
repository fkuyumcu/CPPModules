#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
    Weapon *wpn;
    std::string name;

public:
    HumanB(std::string name);
    ~HumanB();

    void setWeapon(Weapon &wpn);
    void attack();
    Weapon *getWeapon();
};
