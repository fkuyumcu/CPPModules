#include <iostream>
#include "whatever.hpp"

int main() {
    int a = 42, b = 24;
    ::swap(a, b);
    std::cout << "a=" << a << " b=" << b << std::endl;          // a=24 b=42
    std::cout << ::min(a, b) << std::endl;                      // 24
    std::cout << ::max(a, b) << std::endl;                      // 42

    std::string s1 = "Hello", s2 = "World";
    ::swap(s1, s2);
    std::cout << s1 << " " << s2 << std::endl;                  // World Hello
    return 0;
}
