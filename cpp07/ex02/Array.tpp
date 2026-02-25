#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array() : elements(NULL), arraySize(0)
{

}
//creating an empty list in constructor

template<typename T>
Array<T>::Array(unsigned int n) : elements(NULL), arraySize(n)
{
    if (n > 0) {
        elements = new T[n]();
    }
}

template<typename T>
Array<T>::Array(const Array& other) : elements(NULL), arraySize(other.arraySize) {
    if (arraySize > 0) {
        elements = new T[arraySize];
        for (unsigned int i = 0; i < arraySize; ++i) {
            elements[i] = other.elements[i];
        }
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] elements;
        
        arraySize = other.arraySize;
        if (arraySize > 0) {
            elements = new T[arraySize];
            for (unsigned int i = 0; i < arraySize; ++i) {
                elements[i] = other.elements[i];
            }
        } else {
            elements = NULL;
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] elements;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= arraySize) {
        throw std::out_of_range("Array index out of bounds");
    }
    return elements[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= arraySize) {
        throw std::out_of_range("Array index out of bounds");
    }
    return elements[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return arraySize;
}

#endif