#include "Harl.hpp"

void Harl::info()
{
    std::cout << "INFO\n";
}

void Harl::warning()
{
    std::cout << "WARNING\n";
}

void Harl::error()
{
    std::cout << "ERROR\n";
}
void Harl::debug()
{
    std::cout << "DEBUG\n";
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