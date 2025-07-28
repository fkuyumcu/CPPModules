/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 02:47:18 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/27 02:53:57 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout <<BOLD_BLUE<< "Cat Constructor Called" <<RESET<< std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &a) : Animal(a)
{
    std::cout <<BOLD_BLUE<< "Cat Copy Constructor Called" <<RESET<< std::endl;
    this->type = a.type;
    this->brain = new Brain(*a.brain);
}

Cat& Cat::operator=(const Cat &a)
{
    std::cout <<BOLD_BLUE<< "Cat Operator Overload Called" <<RESET<< std::endl;
    if (this != &a)
    {
        this->type = a.type;
        delete this->brain;
        this->brain = new Brain(*a.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout <<BOLD_RED<< "Cat Destructor Called" <<RESET<< std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

