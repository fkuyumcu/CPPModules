#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(99);
    }
    catch (std::exception &e)
    {
        std::cout << "Err: " << e.what() << std::endl;
    }

    Span sp2(1);
    sp2.addNumber(42);
    try
    {
        sp2.shortestSpan();
    }
    catch (std::exception &e) {
        std::cout << "Err: " << e.what() << std::endl;
    }

    Span big(10000);
    std::vector<int> src;
    for (int i = 0; i < 10000; i++)
        src.push_back(i);
    big.addNumbers(src.begin(), src.end());
    std::cout << big.shortestSpan() << std::endl;
    std::cout << big.longestSpan() << std::endl;

    return 0;
}