#include <iostream>
#include <string>

std::string str = "HI THIS IS BRAIN";

std::string *stringPTR = &str;
std::string &stringREF = str;

int main(void)
{
    std::cout << "Memory Address of the String: " << &str << std::endl;
    std::cout << "Memory Address Held By stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory Address Held By stringREF: " << &stringREF << std::endl;

    std::cout << "Value of String: " << str << std::endl;
    std::cout << "The Value Pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The Value Pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}

