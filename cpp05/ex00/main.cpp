#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Valid Bureaucrat Creation ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Default Constructor ===" << std::endl;
    try {
        Bureaucrat def;
        std::cout << def << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Highest Grade (1) ===" << std::endl;
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Lowest Grade (150) ===" << std::endl;
    try {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Grade Too High (0) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Grade Too Low (151) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Increment Grade ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 3);
        std::cout << "Before: " << alice << std::endl;
        alice.incGrade();
        std::cout << "After increment: " << alice << std::endl;
        alice.incGrade();
        std::cout << "After increment: " << alice << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Increment Grade at Maximum (should throw) ===" << std::endl;
    try {
        Bureaucrat topGuy("TopGuy", 1);
        std::cout << "Before: " << topGuy << std::endl;
        topGuy.incGrade(); // This should throw
        std::cout << "After increment: " << topGuy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Decrement Grade ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 148);
        std::cout << "Before: " << charlie << std::endl;
        charlie.decGrade();
        std::cout << "After decrement: " << charlie << std::endl;
        charlie.decGrade();
        std::cout << "After decrement: " << charlie << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 10: Decrement Grade at Minimum (should throw) ===" << std::endl;
    try {
        Bureaucrat lowGuy("LowGuy", 150);
        std::cout << "Before: " << lowGuy << std::endl;
        lowGuy.decGrade(); // This should throw
        std::cout << "After decrement: " << lowGuy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 11: Copy Constructor ===" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 12: Assignment Operator ===" << std::endl;
    try {
        Bureaucrat first("First", 10);
        Bureaucrat second("Second", 100);
        std::cout << "Before assignment:" << std::endl;
        std::cout << "First: " << first << std::endl;
        std::cout << "Second: " << second << std::endl;
        second = first;
        std::cout << "After assignment (second = first):" << std::endl;
        std::cout << "First: " << first << std::endl;
        std::cout << "Second: " << second << " (name stays 'Second', grade becomes 10)" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
