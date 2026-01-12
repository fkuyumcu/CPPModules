#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), is_signed(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
}

AForm::AForm(const std::string n, int gradeToSign, int gradeToExecute) 
    : name(n), is_signed(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &f) 
    : name(f.name), is_signed(f.is_signed), 
      gradeRequiredToSign(f.gradeRequiredToSign), 
      gradeRequiredToExecute(f.gradeRequiredToExecute)
{
}

AForm& AForm::operator=(const AForm &f)
{
    if (this != &f)
        this->is_signed = f.is_signed;
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSigned() const
{
    return this->is_signed;
}

int AForm::getGradeToSign() const
{
    return this->gradeRequiredToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->gradeRequiredToSign)
        throw GradeTooLowException();
    this->is_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->is_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > this->gradeRequiredToExecute)
        throw GradeTooLowException();
    
    this->executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form " << f.getName() << ", signed: " << (f.getSigned() ? "yes" : "no")
       << ", grade required to sign: " << f.getGradeToSign()
       << ", grade required to execute: " << f.getGradeToExecute();
    return os;
}
