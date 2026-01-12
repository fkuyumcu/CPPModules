#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &p);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &p);
        ~PresidentialPardonForm();

        virtual void executeAction() const;
};

#endif
