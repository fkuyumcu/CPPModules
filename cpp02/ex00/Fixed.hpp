/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:33:45 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/10 14:33:46 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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