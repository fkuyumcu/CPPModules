#include <iostream>
#include "iter.hpp"

template<typename T>
void print(const T& x)
{ 
    std::cout << x << " "; 
}

template<typename T>
void doubled(T& x)
{ 
    x *= 2;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print<int>);   
    std::cout << std::endl;
    iter(arr, 5, doubled<int>);
    iter(arr, 5, print<int>);  
    std::cout << std::endl;

    std::string words[] = {"hello", "world"};
    iter(words, 2, print<std::string>);
    std::cout << std::endl;
    return 0;
}
