#include "Bureaucrat.hpp"
 
 //Used to initialize attributes before the constructor body executes
 //This is mandatory for the name attribute because it is defined as a constant

Bureaucrat::Bureaucrat() : name("def"), grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string n, int g) : name(n), grade(g)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &br) : name(br.name), grade(br.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &br)
{
    if (this != &br)
        this->grade = br.grade;

    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br)
{
    os << br.getName() << ", bureaucrat grade " << br.getGrade();
    return os;
}



