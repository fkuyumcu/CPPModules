#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern &i)
{
    (void)i;
}

Intern& Intern::operator=(const Intern &i)
{
    (void)i;
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::createShrubberyForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    // Array of form names
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Array of function pointers (member function pointers)
    AForm* (Intern::*formCreators[3])(const std::string &) = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };

    // Search for matching form name
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    // If no match found, print error message
    std::cout << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
    std::cout << "Available forms: shrubbery creation, robotomy request, presidential pardon" << std::endl;
    return NULL;
}
