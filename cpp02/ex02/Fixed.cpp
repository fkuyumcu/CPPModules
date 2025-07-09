#include "Fixed.hpp"


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}


Fixed::Fixed(const int fixedPoint)
{
	std::cout << "Int constructor called" << std::endl;
	rawBits = fixedPoint << NumOfFractional;
}

	
Fixed::Fixed(const float floatingPoint)
{
	std::cout << "Float constructor called" << std::endl;
	// convert float into fixedpoint
	//kesirden sonraki kısım 8 bit olduğundan dolayı float sayıyı 256 ile çarpıyorum
	//1 << 8 = 256
	rawBits = roundf(floatingPoint * (1 << NumOfFractional));
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
	return this->rawBits >> NumOfFractional;
}
//Operator overloads

Fixed& Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = f.rawBits;
	return *this;
}


std::ostream& operator<<(std::ostream& flo, const Fixed& f)
{
	flo << f.toFloat();
	return flo;
}

bool Fixed::operator<(const Fixed& f1)const
{
	return this->rawBits < f1.rawBits;
}

bool Fixed::operator>(const Fixed& f1)const
{
	return this->rawBits > f1.rawBits;
}
bool Fixed::operator<=(const Fixed& f1)const
{
	return this->rawBits <= f1.rawBits;
}
 
bool Fixed::operator>=(const Fixed& f1)const
{
	return this->rawBits >= f1.rawBits;
}


bool Fixed::operator==(const Fixed& f1)const
{
	return this->rawBits == f1.rawBits;
}


bool Fixed::operator!=(const Fixed& f1)const
{
	return this->rawBits != f1.rawBits;
}


Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.rawBits = this->rawBits + other.rawBits;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.rawBits = this->rawBits - other.rawBits;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.rawBits = (this->rawBits * other.rawBits) >> this->NumOfFractional;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.rawBits = (this->rawBits << this->NumOfFractional) / other.rawBits;
	return result;
}

Fixed& Fixed::min(Fixed &n1, Fixed &n2)
{
	if(n1.rawBits < n2.rawBits)
		return n1;
	else
		return n2;
}
		
const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if(n1.rawBits < n2.rawBits)
		return n1;
	else
		return n2;
}
		
Fixed& Fixed::max(Fixed &n1, Fixed &n2)
{
	if(n1.rawBits > n2.rawBits)
		return n1;
	else
		return n2;

}
		
const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if(n1.rawBits > n2.rawBits)
		return n1;
	else
		return n2;
}

Fixed& Fixed::operator++()
{
    ++rawBits;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    rawBits++;
    return temp;
}

Fixed& Fixed::operator--()
{
    --rawBits;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    rawBits--;
    return temp;
}