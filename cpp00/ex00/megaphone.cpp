#include <iostream>


int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    
    for (int i = 1 ; i < (ac); i++)
    {
        std::string s = av[i];
        for(size_t j = 0; j < s.length(); j++)
        {
            s[j] = std::toupper(s[j]);
        }
        std::cout << s;
        if(i != ac - 1)
            std::cout << " ";
        else 
            std::cout << "\n";
    }
    return (0);
}