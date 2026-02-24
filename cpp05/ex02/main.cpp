#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static void printSection(const std::string &title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
    printSection("ShrubberyCreationForm: success case");
    try {
        ShrubberyCreationForm shrubbery("garden");
        Bureaucrat bob("Bob", 100);
        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSection("Execute without signing");
    try {
        ShrubberyCreationForm unsignedForm("unsigned");
        Bureaucrat alice("Alice", 1);
        alice.executeForm(unsignedForm);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSection("Signed form, executor grade too low");
    try {
        ShrubberyCreationForm shrubbery("office");
        Bureaucrat signer("Signer", 100);
        Bureaucrat lowExecutor("LowExecutor", 150);
        signer.signForm(shrubbery);
        lowExecutor.executeForm(shrubbery);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSection("RobotomyRequestForm: two executions");
    try {
        RobotomyRequestForm robotomy("Bender");
        Bureaucrat chief("Chief", 1);
        chief.signForm(robotomy);
        chief.executeForm(robotomy);
        chief.executeForm(robotomy);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSection("Robotomy sign failure");
    try {
        RobotomyRequestForm robotomy("Target");
        Bureaucrat intern("Intern", 100);
        intern.signForm(robotomy);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSection("PresidentialPardonForm: success case");
    try {
        PresidentialPardonForm pardon("Arthur Dent");
        Bureaucrat president("President", 1);
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
