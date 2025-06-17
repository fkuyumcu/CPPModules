#include "Weapon.hpp"

class HumanB
{
    private:
    Weapon *wpn;
    std::string name;


    public:
    Weapon *getWeapon();
    void setWeapon(Weapon &wpn);
    void attack();
    HumanB(std::string &name);
    ~HumanB();
};
