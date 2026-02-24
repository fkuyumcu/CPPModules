#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

static void printSection(const std::string &title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

static void processForm(AForm *form, Bureaucrat &signer, Bureaucrat &executor)
{
    if (form == NULL)
        return;
    std::cout << *form << std::endl;
    signer.signForm(*form);
    executor.executeForm(*form);
    delete form;
}

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat gardener("Gardener", 100);
    Bureaucrat trainee("Trainee", 150);

    printSection("Intern creates shrubbery form (success)");
    processForm(intern.makeForm("shrubbery creation", "home"), gardener, gardener);

    printSection("Intern creates robotomy form (success)");
    processForm(intern.makeForm("robotomy request", "Bender"), boss, boss);

    printSection("Intern creates pardon form (success)");
    processForm(intern.makeForm("presidential pardon", "Arthur Dent"), boss, boss);

    printSection("Intern with unknown form name");
    AForm *invalid = intern.makeForm("unknown form", "target");
    if (invalid == NULL)
        std::cout << "Returned NULL as expected." << std::endl;

    printSection("Valid form but low-grade execution");
    AForm *hardForm = intern.makeForm("presidential pardon", "LowRankTarget");
    if (hardForm != NULL)
    {
        boss.signForm(*hardForm);
        trainee.executeForm(*hardForm);
        delete hardForm;
    }

    return 0;
}
