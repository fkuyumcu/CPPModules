#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>

template<typename T>
class Array
{
    private:
        T* elements;
        unsigned int arraySize;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
    
        //overloading [] operator for index access 
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
    
        
        unsigned int size() const;
};

#include "Array.tpp"

#endif