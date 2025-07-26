#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor Called" << std::endl;
    this->type = "unknown";
}

Animal::Animal(const Animal &a)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    this->type = a.type;
}

Animal& Animal::operator=(const Animal &a)
{
    std::cout << "Animal Operator Overload Called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}