#include <iostream>
#include <bits/stdc++.h>


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
        std::transform(s.begin(), s.end(), s.begin(), 
                    ::toupper);
        std::cout << s;
        if(i != ac - 1)
            std::cout << " ";
        else 
            std::cout << "\n";
    }
    return (0);
}