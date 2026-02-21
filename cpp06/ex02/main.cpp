#include "Utils.hpp"
#include <iostream>

int main()
{
    Base* ptr1 = generate();
    Base* ptr2 = generate();
    Base* ptr3 = generate();

    std::cout << "\n--- Identify by pointer ---" << std::endl;
    std::cout << "ptr1: ";
    identify(ptr1);
    std::cout << "ptr2: ";
    identify(ptr2);
    std::cout << "ptr3: ";
    identify(ptr3);

    std::cout << "\n--- Identify by reference ---" << std::endl;
    std::cout << "ptr1: ";
    identify(*ptr1);
    std::cout << "ptr2: ";
    identify(*ptr2);
    std::cout << "ptr3: ";
    identify(*ptr3);

    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}
