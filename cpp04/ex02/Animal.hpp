/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 02:47:15 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/27 02:52:38 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    public:
        std::string getType() const;
        Animal();
        Animal(const Animal &a);
        Animal& operator=(const Animal &a);
        virtual ~Animal();
        virtual void makeSound() const = 0;

    protected:
        std::string type;
};

#endif