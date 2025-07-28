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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "Creating objects" << std::endl;
    const Animal* animal = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << " Testing getType() " << std::endl;
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;
    std::cout << "animal type: " << animal->getType() << std::endl;
    
    std::cout << " Testing makeSound() " << std::endl;
    i->makeSound();
    j->makeSound();
    animal->makeSound();
    
    std::cout << " Testing copy constructor " << std::endl;
    Cat cat1;
    Cat cat2(cat1);
    
    std::cout << " Testing assignment operator " << std::endl;
    Dog dog1;
    Dog dog2;
    dog2 = dog1;
    
    std::cout << " Deleting objects " << std::endl;
    delete animal;
    delete j;
    delete i;
    
    std::cout << "Testing Wrong Animals" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
    std::cout << "wrongMeta type: " << wrongMeta->getType() << std::endl;
    
    std::cout << "wrong sounds:" << std::endl;

    wrongCat->makeSound();
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    return 0;
}