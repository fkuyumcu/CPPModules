#include "Span.hpp"

Span::Span(unsigned int n) : max(n)
{

}

Span::Span(const Span &other) : max(other.max), data(other.data)
{

}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        max = other.max;
        data = other.data;
    }
    return *this;
}

Span::~Span() 
{

}

void Span::addNumber(int n)
{
    if (data.size() >= max)
        throw std::runtime_error("Span is full");
    data.push_back(n);
}

int Span::shortestSpan() const
{
    if (data.size() < 2)
        throw std::runtime_error("Not enough elements");

    std::vector<int> sorted(data);
    std::sort(sorted.begin(), sorted.end());

    int shortest = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (data.size() < 2)
        throw std::runtime_error("Not enough elements");

    int max = *std::max_element(data.begin(), data.end());
    int min = *std::min_element(data.begin(), data.end());
    return max - min;
}