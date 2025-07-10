/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:34:11 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/10 14:34:12 by fkuyumcu         ###   ########.fr       */
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

        bool operator<(const Fixed& f1)const;
        bool operator>(const Fixed& f1)const;
        bool operator<=(const Fixed& f1)const;
        bool operator>=(const Fixed& f1)const;
        bool operator==(const Fixed& f1)const;
        bool operator!=(const Fixed& f1)const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();        
        Fixed operator--(int);
        
        float toFloat( void ) const;
        int toInt( void ) const;

        static Fixed& min(Fixed &n1, Fixed &n2); 
        static const Fixed& min(const Fixed &n1, const Fixed &n2); 
        static Fixed& max(Fixed &n1, Fixed &n2); 
        static const Fixed& max(const Fixed &n1, const Fixed &n2); 


        

    private:
    	static const int	NumOfFractional = 8;
        int rawBits;

};
std::ostream& operator<<(std::ostream& os, const Fixed& f);






#endif
