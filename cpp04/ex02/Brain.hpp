#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain &b);
        Brain& operator=(const Brain &b);
        ~Brain();
        std::string ideas[100];

    private:

};

#endif