#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon &wpn;
    
    public:
        HumanA(const std::string &name, Weapon &wpn);
        ~HumanA();
        void attack();
    };
    