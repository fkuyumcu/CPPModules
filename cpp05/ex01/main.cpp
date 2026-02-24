#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void printSection(const std::string &title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
    printSection("Create valid objects");
    try {
        Bureaucrat bob("Bob", 50);
        Form contract("Contract", 50, 30);
        std::cout << bob << std::endl;
        std::cout << contract << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSection("Successful signing");
    try {
        Bureaucrat signer("Signer", 50);
        Form permit("Permit", 50, 20);
        std::cout << "Before: " << permit << std::endl;
        signer.signForm(permit);
        std::cout << "After:  " << permit << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSection("Failed signing (grade too low)");
    try {
        Bureaucrat junior("Junior", 120);
        Form secret("TopSecret", 10, 5);
        std::cout << "Before: " << secret << std::endl;
        junior.signForm(secret);
        std::cout << "After:  " << secret << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSection("Invalid form constructor inputs");
    try {
        Form invalidHigh("InvalidHigh", 0, 50);
        std::cout << invalidHigh << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Creating sign grade 0 failed: " << e.what() << std::endl;
    }
    try {
        Form invalidLow("InvalidLow", 40, 151);
        std::cout << invalidLow << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Creating execute grade 151 failed: " << e.what() << std::endl;
    }

    return 0;
}
