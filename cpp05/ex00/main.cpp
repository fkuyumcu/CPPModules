#include "Bureaucrat.hpp"
#include <iostream>

static void printSection(const std::string &title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
    printSection("Valid bureaucrat and grade changes");
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << "Start: " << bob << std::endl;
        bob.incGrade();
        std::cout << "After incGrade(): " << bob << std::endl;
        bob.decGrade();
        std::cout << "After decGrade(): " << bob << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSection("Constructor boundary checks");
    try {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Creating grade 0 failed: " << e.what() << std::endl;
    }
    try {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Creating grade 151 failed: " << e.what() << std::endl;
    }

    printSection("Operation boundary checks");
    try {
        Bureaucrat top("Top", 1);
        std::cout << "Before incGrade(): " << top << std::endl;
        top.incGrade();
    }
    catch (std::exception &e) {
        std::cout << "incGrade at grade 1 failed: " << e.what() << std::endl;
    }
    try {
        Bureaucrat bottom("Bottom", 150);
        std::cout << "Before decGrade(): " << bottom << std::endl;
        bottom.decGrade();
    }
    catch (std::exception &e) {
        std::cout << "decGrade at grade 150 failed: " << e.what() << std::endl;
    }

    printSection("Copy and assignment");
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Assigned", 100);
        assigned = original;

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
