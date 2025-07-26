#include "Animal.hpp"



Cat::Cat()
{
    std::cout << "Cat Constructor Called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &a) : Animal(a)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    this->type = a.type;

}

Cat& Cat::operator=(const Cat &a)
{
    std::cout << "Cat Operator Overload Called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}

Dog::Dog()
{
    std::cout << "Dog Constructor Called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &a) : Animal(a)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    this->type = a.type;
}

Dog& Dog::operator=(const Dog &a)
{
    std::cout << "Dog Operator Overload Called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a generic sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

int main(void)
{
    std::cout << "Creating objects" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << " Testing getType() " << std::endl;
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;
    
    std::cout << " Testing makeSound() " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    std::cout << " Testing copy constructor " << std::endl;
    Cat cat1;
    Cat cat2(cat1);
    
    std::cout << " Testing assignment operator " << std::endl;
    Dog dog1;
    Dog dog2;
    dog2 = dog1;
    
    std::cout << " Deleting objects " << std::endl;
    delete meta;
    delete j;
    delete i;
    
    return 0;
}