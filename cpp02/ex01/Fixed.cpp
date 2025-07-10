/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:33:56 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/10 15:11:31 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor and destructor functions

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}


Fixed::Fixed(const int integer)
{
    //convert integer into fixedpoint
    std::cout << "Int constructor called" << std::endl;
    setRawBits(integer << NumOfFractional);
}

    
Fixed::Fixed(const float floatingPoint)
{
    std::cout << "Float constructor called" << std::endl;
    // convert float into fixedpoint
    //1 << 8 = 256
    setRawBits(roundf(floatingPoint * (1 << NumOfFractional)));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//Converter Functions

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->rawBits) / (1 << NumOfFractional);
}

int Fixed::toInt(void) const
{
    return this->getRawBits() >> NumOfFractional;
}
//Operator overloads

Fixed& Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(f.getRawBits());
    return *this;
}


std::ostream& operator<<(std::ostream& flo, const Fixed& f)
{
    flo << f.toFloat();
    return flo;
}

int Fixed::getRawBits( void ) const
{
    return this->rawBits;
}

void Fixed::setRawBits( int const raw )
{
    this->rawBits = raw;
}
