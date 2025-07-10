/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:33:59 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/10 14:34:00 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
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
        int		getRawBits( void ) const;
    	void	setRawBits( int const raw );

    private:
    	static const int	NumOfFractional = 8;
        int rawBits;

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
