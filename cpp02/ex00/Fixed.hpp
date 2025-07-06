#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
    public:
    	Fixed();
    	Fixed(const Fixed &f);
    	Fixed& operator=(const Fixed &f);
    	~Fixed();
    	int		getRawBits( void ) const;
    	void	setRawBits( int const raw );


    private:
    	int					FixedValue;
    	static const int	NumOfFractional = 8;


};

#endif