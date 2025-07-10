/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:34:15 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/07/10 15:53:51 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;                    // Default constructor
    Fixed b(42);               // Int constructor
    Fixed c(3.14f);            // Float constructor
    Fixed d(c);                // Copy constructor
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    
    std::cout << "b.toInt(): " << b.toInt() << std::endl;
    std::cout << "c.toFloat(): " << c.toFloat() << std::endl;
    
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "c < b: " << (c < b) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "b >= a: " << (b >= a) << std::endl;
    
    Fixed sum = b + c;
    Fixed diff = b - c;
    Fixed mult = c * Fixed(2);
    Fixed div = b / Fixed(2);
    
    std::cout << "b + c = " << sum << std::endl;
    std::cout << "b - c = " << diff << std::endl;
    std::cout << "c * 2 = " << mult << std::endl;
    std::cout << "b / 2 = " << div << std::endl;
    
    Fixed f(5.5f);
    Fixed g(2.2f);
    std::cout << "f: " << f << ", g: " << g << std::endl;
    std::cout << "min(f, g): " << Fixed::min(f, g) << std::endl;
    std::cout << "max(f, g): " << Fixed::max(f, g) << std::endl;
    
    const Fixed h(1.1f);
    const Fixed i(9.9f);
    std::cout << "const min(h, i): " << Fixed::min(h, i) << std::endl;
    std::cout << "const max(h, i): " << Fixed::max(h, i) << std::endl;

    
    return 0;
}