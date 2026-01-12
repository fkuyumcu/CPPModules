#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
    public:
        Intern();
        Intern(const Intern &i);
        Intern& operator=(const Intern &i);
        ~Intern();

        AForm* makeForm(const std::string &formName, const std::string &target);

    private:
        // Helper functions for creating specific forms
        AForm* createShrubberyForm(const std::string &target);
        AForm* createRobotomyForm(const std::string &target);
        AForm* createPresidentialForm(const std::string &target);
};

#endif
