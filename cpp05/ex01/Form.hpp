#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;

    public:
        Form();
        Form(const std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &f);
        Form& operator=(const Form &f);
        ~Form();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        // Getters
        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // Member function
        void beSigned(const Bureaucrat &b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif