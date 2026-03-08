#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int main()
{
    // --- subject testi ---
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;  // 2
    std::cout << sp.longestSpan() << std::endl;   // 14

    // --- dolu span ---
    try {
        sp.addNumber(99);
    } catch (std::exception &e) {
        std::cout << "Hata: " << e.what() << std::endl;
    }

    // --- tek eleman ---
    Span sp2(1);
    sp2.addNumber(42);
    try {
        sp2.shortestSpan();
    } catch (std::exception &e) {
        std::cout << "Hata: " << e.what() << std::endl;
    }

    // --- vector iterator ile toplu ekleme ---
    Span big(10000);
    std::vector<int> src;
    for (int i = 0; i < 10000; i++)
        src.push_back(i);
    big.addNumbers(src.begin(), src.end());
    std::cout << big.shortestSpan() << std::endl;  // 1
    std::cout << big.longestSpan() << std::endl;   // 9999

    // --- list iterator ile toplu ekleme ---
    Span sp3(5);
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    sp3.addNumbers(lst.begin(), lst.end());
    std::cout << sp3.shortestSpan() << std::endl;  // 10
    std::cout << sp3.longestSpan() << std::endl;   // 40

    return 0;
}