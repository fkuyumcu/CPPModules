#include "Harl.hpp"

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
    std::cout << "think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n";
}

void Harl::complain(std::string level)
{
    typedef void(Harl::*UF)();
    std::string levels[4] = {"DEBUG","INFO", "WARNING","ERROR"};
    UF functions[4] = {&Harl::debug,&Harl::info,&Harl::warning, &Harl::error};

    for(int i = 0; i < 4; i++)
    {
        if(levels[i] == level)
        {
            (this->*functions[i])();
            return ;
        }
    }
    std::cout << "unknown level\n";
}

Harl::Harl()
{

};

Harl::~Harl()
{

};