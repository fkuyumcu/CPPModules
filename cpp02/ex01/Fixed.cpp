/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:33:56 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/10 14:33:57 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor and destructor functions

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}


Fixed::Fixed(const int fixedPoint)
{
    std::cout << "Int constructor called" << std::endl;
    //integer sayıları fixedpoint olarak saklarken yalnızca sağa ya da sola kaydırarak çevirebiliyoruz
    setRawBits(fixedPoint << NumOfFractional);
}

    
Fixed::Fixed(const float floatingPoint)
{
    std::cout << "Float constructor called" << std::endl;
    // convert float into fixedpoint
    //kesirden sonraki kısım 8 bit olduğundan dolayı float sayıyı 256 ile çarpıyorum
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
    //cpp02'de static cast gerekli mi?
    return static_cast<float>(this->rawBits) / (1 << NumOfFractional);
    //1 << 8 = 256 yapar, floatig point sayıyı fixed hale getirirken round ile yuvarlamıştık. şimdi de static cast ile float hale getiriyorum 
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
