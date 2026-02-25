#include <iostream>
#include <string>
#include "iter.hpp"


void increment(int& n) {
    n++;
    std::cout << n << " ";
}

void print(const int& n) {
    std::cout << n << " ";
}

void printString(const std::string& str) {
    std::cout << "'" << str << "' ";
}
void toUppercase(std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    std::cout << "'" << str << "' ";
}

template<typename T>
void printGeneric(const T& element) {
    std::cout << "[" << element << "] ";
}

template<typename T>
void multiplyBy2(T& element) {
    element = element * 2;
    std::cout << element << " ";
}

void printConstInt(const int& n) {
    std::cout << n << " ";
}

int main() {
    std::cout << "=== Testing iter function template ===" << std::endl << std::endl;

    std::cout << "1. Non-const int array with increment function:" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << "Before: ";
    iter(numbers, numbersSize, print);
    std::cout << std::endl << "After increment: ";
    iter(numbers, numbersSize, increment);
    std::cout << std::endl << std::endl;

    // Test 2: Const int array with read-only function
    std::cout << "2. Const int array with read-only function:" << std::endl;
    const int constNumbers[] = {10, 20, 30, 40, 50};
    size_t constNumbersSize = sizeof(constNumbers) / sizeof(constNumbers[0]);
    std::cout << "Const array: ";
    iter(constNumbers, constNumbersSize, printConstInt);
    std::cout << std::endl << std::endl;

    // Test 3: String array with function that modifies elements
    std::cout << "3. String array with modification function:" << std::endl;
    std::string words[] = {"hello", "world", "cpp", "templates"};
    size_t wordsSize = sizeof(words) / sizeof(words[0]);
    std::cout << "Before: ";
    iter(words, wordsSize, printString);
    std::cout << std::endl << "After uppercase: ";
    iter(words, wordsSize, toUppercase);
    std::cout << std::endl << std::endl;

    // Test 4: Using function template (instantiated)
    std::cout << "4. Using instantiated function template:" << std::endl;
    double doubles[] = {1.5, 2.5, 3.5, 4.5};
    size_t doublesSize = sizeof(doubles) / sizeof(doubles[0]);
    std::cout << "Generic print: ";
    iter(doubles, doublesSize, printGeneric<double>);
    std::cout << std::endl;
    std::cout << "Multiply by 2: ";
    iter(doubles, doublesSize, multiplyBy2<double>);
    std::cout << std::endl << std::endl;


    return 0;
}
