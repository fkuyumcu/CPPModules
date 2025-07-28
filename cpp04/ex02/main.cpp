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
    std::cout << BOLD_GREEN << "Basic Tests" << RESET << std::endl;
    //const Animal* Anm = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    
    std::cout << BOLD_GREEN << "Testing getType()" << RESET << std::endl;
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;
    //std::cout << "Anm type: " << Anm->getType() << std::endl;
    
    std::cout << BOLD_GREEN << "Testing makeSound()" <<RESET<< std::endl;
    i->makeSound();
    j->makeSound();
    //Anm->makeSound();
        
    std::cout << BOLD_GREEN << "Deep Copy Tests" <<RESET<< std::endl;
    
    std::cout << BOLD_GREEN << "Testing copy constructor:" << RESET << std::endl;
    Cat cat1;
    Cat cat2(cat1);
    
    std::cout << BOLD_GREEN << "Testing assignment operator:" <<RESET<< std::endl;
    Dog dog1;
    Dog dog2;
    dog2 = dog1;
    
    std::cout << BOLD_GREEN << "Array of Animals Tests" <<RESET<< std::endl;
    const int SIZE = 10;
    Animal* animals[SIZE];
    
    for (int i = 0; i < SIZE; i++)
    {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    std::cout << BOLD_GREEN <<  "Testing all animals:" << RESET << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        delete animals[i];
    }
    
    std::cout << BOLD_GREEN << "Testing Wrong Animals:" << RESET << std::endl;

    const WrongAnimal* wrongAnm = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
    std::cout << "wrongAnm type: " << wrongAnm->getType() << std::endl;
    
    std::cout << "Wrong sounds:" << std::endl;
    wrongCat->makeSound();
    wrongAnm->makeSound();

    std::cout << BOLD_GREEN << "Deep Copy Tests" << RESET << std::endl;
    Dog dog3;
    Dog dog4;
    
    dog3 = dog4;
    
    std::cout << "dog1 brain address: " << &dog3 << std::endl;
    std::cout << "dog2 brain address: " << &dog4 << std::endl;
    
    
    delete wrongAnm;
    delete wrongCat;
    //delete Anm;
    delete j;
    delete i;
    
    return 0;
}