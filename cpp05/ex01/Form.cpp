#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("name"), is_signed(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
}

Form::Form(const std::string n, int gradeToSign, int gradeToExecute) 
    : name(n), is_signed(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &f) 
    : name(f.name), is_signed(f.is_signed), 
      gradeRequiredToSign(f.gradeRequiredToSign), 
      gradeRequiredToExecute(f.gradeRequiredToExecute)
{
    
}

Form& Form::operator=(const Form &f)
{
    if (this != &f)
        this->is_signed = f.is_signed;
    return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getSigned() const
{
    return this->is_signed;
}

int Form::getGradeToSign() const
{
    return this->gradeRequiredToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->gradeRequiredToSign)
        throw GradeTooLowException();
    this->is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form " << f.getName() << ", signed: " << (f.getSigned() ? "yes" : "no")
       << ", grade required to sign: " << f.getGradeToSign()
       << ", grade required to execute: " << f.getGradeToExecute();
    return os;
}
