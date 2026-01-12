#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string t) 
    : AForm("ShrubberyCreationForm", 145, 137), target(t)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) 
    : AForm(s), target(s.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
    if (this != &s)
    {
        AForm::operator=(s);
        this->target = s.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    file << "       ###" << std::endl;
    file << "      #o###" << std::endl;
    file << "    #####o###" << std::endl;
    file << "   #o#\\#|#/###" << std::endl;
    file << "    ###\\|/#o#" << std::endl;
    file << "     # }|{  #" << std::endl;
    file << "       }|{" << std::endl;
    file << std::endl;
    file << "      ^###^" << std::endl;
    file << "     ## # ##" << std::endl;
    file << "    #  ###  #" << std::endl;
    file << "   # #  #  # #" << std::endl;
    file << "  ###  # #  ###" << std::endl;
    file << "   #    #    #" << std::endl;
    file << "       | |" << std::endl;
    file << "       | |" << std::endl;
    file << "      _|_|_" << std::endl;

    file.close();
    std::cout << "Shrubbery has been created at " << filename << std::endl;
}
