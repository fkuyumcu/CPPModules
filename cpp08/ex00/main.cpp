#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(34);
    vec.push_back(41);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "found in vector: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Err: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "found in vector:" << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Err:: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "found in list " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Err: " << e.what() << std::endl;
    }

    return 0;
}