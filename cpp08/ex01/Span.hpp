#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        unsigned int        max;
        std::vector<int>    data;
    public:
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);
        int  shortestSpan() const;
        int  longestSpan() const;

        template <typename T>
        void addNumbers(T first, T last)
        {
            while (first != last)
            {
                addNumber(*first);
                first++;
            }
        }
};




#endif