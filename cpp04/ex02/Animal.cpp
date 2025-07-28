/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 02:47:12 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/27 02:47:13 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor Called" << std::endl;
    this->type = "unknown";
}

Animal::Animal(const Animal &a)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    this->type = a.type;
}

Animal& Animal::operator=(const Animal &a)
{
    std::cout << "Animal Operator Overload Called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}