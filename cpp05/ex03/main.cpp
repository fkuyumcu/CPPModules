#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    std::cout << "============ SHRUBBERY CREATION FORM TESTS ============" << std::endl;
    
    std::cout << "\n=== Test 1: Create and Execute ShrubberyCreationForm ===" << std::endl;
    try {
        ShrubberyCreationForm shrubbery("home");
        Bureaucrat bob("Bob", 100);
        
        std::cout << shrubbery << std::endl;
        std::cout << bob << std::endl;
        
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Execute Without Signing ===" << std::endl;
    try {
        ShrubberyCreationForm shrubbery("garden");
        Bureaucrat alice("Alice", 50);
        
        std::cout << "Attempting to execute unsigned form..." << std::endl;
        alice.executeForm(shrubbery);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Sign but Grade Too Low to Execute ===" << std::endl;
    try {
        ShrubberyCreationForm shrubbery("park");
        Bureaucrat highRank("HighRank", 100);
        Bureaucrat lowRank("LowRank", 140);
        
        highRank.signForm(shrubbery);
        std::cout << "Trying to execute with low-ranked bureaucrat..." << std::endl;
        lowRank.executeForm(shrubbery);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n============ ROBOTOMY REQUEST FORM TESTS ============" << std::endl;
    
    std::cout << "\n=== Test 4: Create and Execute RobotomyRequestForm ===" << std::endl;
    try {
        RobotomyRequestForm robotomy("Bender");
        Bureaucrat charlie("Charlie", 40);
        
        std::cout << robotomy << std::endl;
        std::cout << charlie << std::endl;
        
        charlie.signForm(robotomy);
        charlie.executeForm(robotomy);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Multiple Robotomy Attempts (Testing Randomness) ===" << std::endl;
    try {
        Bureaucrat master("Master", 1);
        
        for (int i = 1; i <= 3; i++) {
            RobotomyRequestForm robotomy("Target" + std::string(1, '0' + i));
            master.signForm(robotomy);
            std::cout << "\nAttempt " << i << ":" << std::endl;
            master.executeForm(robotomy);
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Grade Too Low to Sign Robotomy ===" << std::endl;
    try {
        RobotomyRequestForm robotomy("Victim");
        Bureaucrat lowGrade("LowGrade", 100);
        
        std::cout << "Attempting to sign with grade 100 (requires 72)..." << std::endl;
        lowGrade.signForm(robotomy);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n============ PRESIDENTIAL PARDON FORM TESTS ============" << std::endl;
    
    std::cout << "\n=== Test 7: Create and Execute PresidentialPardonForm ===" << std::endl;
    try {
        PresidentialPardonForm pardon("Arthur Dent");
        Bureaucrat president("President", 1);
        
        std::cout << pardon << std::endl;
        std::cout << president << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Grade Too Low to Sign Presidential Pardon ===" << std::endl;
    try {
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat midLevel("MidLevel", 30);
        
        std::cout << "Attempting to sign with grade 30 (requires 25)..." << std::endl;
        midLevel.signForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Sign but Grade Too Low to Execute Presidential Pardon ===" << std::endl;
    try {
        PresidentialPardonForm pardon("Zaphod");
        Bureaucrat signer("Signer", 20);
        Bureaucrat executor("Executor", 10);
        
        signer.signForm(pardon);
        std::cout << "Trying to execute with grade 10 (requires 5)..." << std::endl;
        executor.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n============ MIXED TESTS ============" << std::endl;
    
    std::cout << "\n=== Test 10: One Bureaucrat, Multiple Forms ===" << std::endl;
    try {
        Bureaucrat supreme("Supreme", 1);
        
        ShrubberyCreationForm shrub("office");
        RobotomyRequestForm robot("Employee");
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << "\n--- Processing Shrubbery Form ---" << std::endl;
        supreme.signForm(shrub);
        supreme.executeForm(shrub);
        
        std::cout << "\n--- Processing Robotomy Form ---" << std::endl;
        supreme.signForm(robot);
        supreme.executeForm(robot);
        
        std::cout << "\n--- Processing Presidential Pardon ---" << std::endl;
        supreme.signForm(pardon);
        supreme.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 11: Copy Constructor Test ===" << std::endl;
    try {
        ShrubberyCreationForm original("original");
        Bureaucrat signer("Signer", 1);
        
        signer.signForm(original);
        ShrubberyCreationForm copy(original);
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        
        std::cout << "Executing copy..." << std::endl;
        signer.executeForm(copy);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 12: Edge Cases - Exact Grade Requirements ===" << std::endl;
    try {
        ShrubberyCreationForm shrub("boundary");
        Bureaucrat exactSign("ExactSign", 145);
        Bureaucrat exactExec("ExactExec", 137);
        
        std::cout << "Signing with exact grade (145)..." << std::endl;
        exactSign.signForm(shrub);
        
        std::cout << "Executing with exact grade (137)..." << std::endl;
        exactExec.executeForm(shrub);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n============ INTERN TESTS ============" << std::endl;

    std::cout << "\n=== Test 13: Intern Creates Robotomy Request ===" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            
            Bureaucrat boss("Boss", 1);
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            
            delete rrf;
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 14: Intern Creates Shrubbery Creation ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("shrubbery creation", "office");
        if (form)
        {
            std::cout << *form << std::endl;
            
            Bureaucrat gardener("Gardener", 100);
            gardener.signForm(*form);
            gardener.executeForm(*form);
            
            delete form;
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 15: Intern Creates Presidential Pardon ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("presidential pardon", "Arthur Dent");
        if (form)
        {
            std::cout << *form << std::endl;
            
            Bureaucrat president("President", 1);
            president.signForm(*form);
            president.executeForm(*form);
            
            delete form;
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 16: Intern - Invalid Form Name ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("invalid form", "target");
        if (form == NULL)
            std::cout << "Form creation failed as expected (returned NULL)" << std::endl;
        else
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 17: Intern - Case Sensitivity Test ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        std::cout << "Trying with uppercase 'ROBOTOMY REQUEST':" << std::endl;
        form = intern.makeForm("ROBOTOMY REQUEST", "test");
        if (form == NULL)
            std::cout << "Form creation failed (case sensitive)" << std::endl;
        else
        {
            delete form;
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 18: Intern Creates Multiple Forms ===" << std::endl;
    try {
        Intern intern;
        AForm* forms[3];
        Bureaucrat vip("VIP", 1);
        
        forms[0] = intern.makeForm("shrubbery creation", "yard");
        forms[1] = intern.makeForm("robotomy request", "Marvin");
        forms[2] = intern.makeForm("presidential pardon", "Ford Prefect");
        
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
            {
                std::cout << "\n" << *forms[i] << std::endl;
                vip.signForm(*forms[i]);
                vip.executeForm(*forms[i]);
                delete forms[i];
            }
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 19: Intern - Empty Form Name ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("", "target");
        if (form == NULL)
            std::cout << "Form creation failed as expected" << std::endl;
        else
            delete form;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 20: Intern Copy Constructor ===" << std::endl;
    try {
        Intern intern1;
        Intern intern2(intern1);
        
        AForm* form1 = intern1.makeForm("robotomy request", "Target1");
        AForm* form2 = intern2.makeForm("presidential pardon", "Target2");
        
        if (form1)
        {
            std::cout << *form1 << std::endl;
            delete form1;
        }
        if (form2)
        {
            std::cout << *form2 << std::endl;
            delete form2;
        }
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
