/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 03:00:00 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/27 02:56:10 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Constructor Called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &a) : WrongAnimal(a)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
    this->type = a.type;
}

WrongCat& WrongCat::operator=(const WrongCat &a)
{
    std::cout << "WrongCat Operator Overload Called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Meow" << std::endl;
}
