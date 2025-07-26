#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Cat.hpp"
#include "Dog.hpp"
#include "string"
#include "iostream"

class Animal
{
    public:
        std::string getType() const;
        Animal();
        Animal(const Animal &a);
        Animal& operator=(const Animal &a);
        virtual ~Animal();
        virtual void makeSound() const;

    protected:
        std::string type;
};


#endif