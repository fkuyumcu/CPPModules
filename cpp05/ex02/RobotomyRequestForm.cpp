#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string t) 
    : AForm("RobotomyRequestForm", 72, 45), target(t)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) 
    : AForm(r), target(r.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &r)
{
    if (this != &r)
    {
        AForm::operator=(r);
        this->target = r.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* DRILLING NOISES * Bzzzzzzz... Wrrrrrr... Clank clank!" << std::endl;
    
    std::srand(std::time(NULL));
    
    if (std::rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy of " << this->target << " failed!" << std::endl;
}
