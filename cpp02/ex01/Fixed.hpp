#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const int fixedPoint);
        Fixed(const float floatingPoint);
        Fixed(const Fixed &f);
        Fixed &operator=(const Fixed &f);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
        
    private:
    	static const int	NumOfFractional = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
