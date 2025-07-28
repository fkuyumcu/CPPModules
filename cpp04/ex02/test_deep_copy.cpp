#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
    Dog dog1;
    Dog dog2;
    
    // Assignment operator test
    dog2 = dog1;
    
    // Deep copy test - farklı Brain pointer'ları olmalı
    std::cout << "dog1 brain address: " << &dog1 << std::endl;
    std::cout << "dog2 brain address: " << &dog2 << std::endl;
    
    return 0;
}
