/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 03:00:00 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/27 02:56:09 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor Called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
    this->type = a.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a)
{
    std::cout << "WrongAnimal Operator Overload Called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a generic sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}
