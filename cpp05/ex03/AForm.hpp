#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;

    public:
        AForm();
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &f);
        AForm& operator=(const AForm &f);
        virtual ~AForm();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        // Getters
        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // Member functions
        void beSigned(const Bureaucrat &b);
        void execute(Bureaucrat const & executor) const;
        
        // Pure virtual function - makes this class abstract
        virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
