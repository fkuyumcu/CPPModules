#include <iostream>
#include "whatever.hpp"

int main() {
    // Test swap function
    std::cout << "=== Testing swap function ===" << std::endl;
    int a = 42, b = 24;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    // Test with strings
    std::string str1 = "Hello", str2 = "World";
    std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    swap(str1, str2);
    std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;

    std::cout << std::endl;

    // Test min function
    std::cout << "=== Testing min function ===" << std::endl;
    int x = 10, y = 20;
    std::cout << "min(" << x << ", " << y << ") = " << min(x, y) << std::endl;
    std::cout << "min(" << y << ", " << x << ") = " << min(y, x) << std::endl;
    
    // Test equal values (should return second parameter)
    int equal1 = 15, equal2 = 15;
    std::cout << "min(" << equal1 << ", " << equal2 << ") = " << min(equal1, equal2) << " (should return second when equal)" << std::endl;

    std::cout << std::endl;

    // Test max function
    std::cout << "=== Testing max function ===" << std::endl;
    std::cout << "max(" << x << ", " << y << ") = " << max(x, y) << std::endl;
    std::cout << "max(" << y << ", " << x << ") = " << max(y, x) << std::endl;
    
    // Test equal values (should return second parameter)
    std::cout << "max(" << equal1 << ", " << equal2 << ") = " << max(equal1, equal2) << " (should return second when equal)" << std::endl;

    std::cout << std::endl;

    // Test with different types
    std::cout << "=== Testing with different types ===" << std::endl;
    double d1 = 3.14, d2 = 2.71;
    std::cout << "min(" << d1 << ", " << d2 << ") = " << min(d1, d2) << std::endl;
    std::cout << "max(" << d1 << ", " << d2 << ") = " << max(d1, d2) << std::endl;

    char c1 = 'a', c2 = 'z';
    std::cout << "min('" << c1 << "', '" << c2 << "') = '" << min(c1, c2) << "'" << std::endl;
    std::cout << "max('" << c1 << "', '" << c2 << "') = '" << max(c1, c2) << "'" << std::endl;

    return 0;
}
