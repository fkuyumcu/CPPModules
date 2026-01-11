#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string t) 
    : AForm("PresidentialPardonForm", 25, 5), target(t)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) 
    : AForm(p), target(p.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
    if (this != &p)
    {
        AForm::operator=(p);
        this->target = p.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
