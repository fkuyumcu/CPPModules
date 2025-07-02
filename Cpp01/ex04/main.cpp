#include "Sed.hpp"
#include <iostream>
#include <string>
#include "fstream"

int main(int ac, char **av)
{
    
    if(ac != 4 || std::string(av[1]).empty() || std::string(av[2]).empty() || std::string(av[3]).empty())
    {
        std::cerr << "Error";
        exit(1);
    }
    std::ifstream infile(av[1]);
    
    infile.open(av[1]);
    
    if(!infile)
    {
        std::cerr << "Error Opening File";
        exit(1);
    }
    std::ofstream outfile(std::string(av[1]) + ".replace");
    if(!outfile)
    {
        std::cerr << "Error Creating File";
        infile.close();
        exit(1);
    }

    std::stringstream buffer;
    buffer << infil

    infile.close();

}