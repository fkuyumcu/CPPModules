#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int ac, char **av)
{
    if (ac == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    
    for (int i = 1 ; i < (ac); i++)
    {
        string s = av[i];
        transform(s.begin(), s.end(), s.begin(), 
                    ::toupper);
        cout << s;
        if(i != ac - 1)
            cout << " ";
        else 
            cout << "\n";
    }
    return (0);
}