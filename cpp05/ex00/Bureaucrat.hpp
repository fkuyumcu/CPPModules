#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
    public:
        //Orthodox Canon.
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &br);
        Bureaucrat& operator=(const Bureaucrat &br);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };



      //getters and setters
        std::string getName() const;
        int     getGrade() const;
        void    incGrade();
        void    decGrade();

    private:
        const std::string name;
        int grade; 

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br);

#endif