#include "Sed.hpp"


int main(int ac, char **av)
{
    
    if(ac != 4 || std::string(av[1]).empty() || std::string(av[2]).empty() || std::string(av[3]).empty())
    {
        std::cerr << "Error";
        exit(1);
    }
    std::ifstream infile(av[1]);
    
    if(!infile.is_open())
    {
        std::cerr << "Error Opening File";
        exit(1);
    }

    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();

    infile.close();
    
    std::ofstream outfile(std::string(av[1]) + ".replace");
    if(!outfile.is_open())
    {
        std::cerr << "Error Creating File";
        exit(1);
    }
    outfile << ft_replace(content, av[2], av[3]);
    outfile.close();

}
