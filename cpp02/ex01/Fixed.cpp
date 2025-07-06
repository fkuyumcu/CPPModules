#include "Fixed.hpp"

Fixed::Fixed()
{

}


Fixed::Fixed(const int fixedPoint)
{

}

    
Fixed::Fixed(const float floatingPoint)
{

}

Fixed::~Fixed()
{

}

float Fixed::toFloat(void) const
{

}

int Fixed::toInt(void) const
{
    
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}

