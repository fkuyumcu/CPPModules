#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &r);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &r);
        ~RobotomyRequestForm();

        virtual void executeAction() const;
};

#endif
