#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "string"
#include "iostream"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &a);
        Cat& operator=(const Cat &a);
        ~Cat();
        void makeSound() const;
};


#endif