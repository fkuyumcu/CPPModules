/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 02:47:29 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/27 02:56:20 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "=== Basic Tests ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\nTesting getType()" << std::endl;
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;
    
    std::cout << "\nTesting makeSound()" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    std::cout << "\nDeleting basic objects" << std::endl;
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Deep Copy Tests ===" << std::endl;
    std::cout << "Testing copy constructor:" << std::endl;
    Cat cat1;
    Cat cat2(cat1);
    
    std::cout << "\nTesting assignment operator:" << std::endl;
    Dog dog1;
    Dog dog2;
    dog2 = dog1;
    
    std::cout << "\n=== Array of Animals Tests ===" << std::endl;
    const int ARRAY_SIZE = 10;
    Animal* animals[ARRAY_SIZE];
    
    // Fill half with Dogs, half with Cats
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (i < ARRAY_SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    std::cout << "\nTesting all animals make sound:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\nDeleting all animals as Animal pointers:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        delete animals[i];
    }
    
    std::cout << "\n=== Testing Wrong Animals ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
    std::cout << "wrongMeta type: " << wrongMeta->getType() << std::endl;
    
    std::cout << "Wrong sounds:" << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    return 0;
}