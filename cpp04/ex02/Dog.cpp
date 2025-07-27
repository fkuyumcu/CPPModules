/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 02:47:23 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/27 02:53:54 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor Called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &a) : Animal(a)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    this->type = a.type;
    this->brain = new Brain(*a.brain);
}

Dog& Dog::operator=(const Dog &a)
{
    std::cout << "Dog Operator Overload Called" << std::endl;
    if (this != &a)
    {
        this->type = a.type;
        delete this->brain;
        this->brain = new Brain(*a.brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}




