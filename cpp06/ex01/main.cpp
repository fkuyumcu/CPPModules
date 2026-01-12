#include "Serialize.hpp"
#include <iostream>

int main()
{
    Data original;
    original.name = "Test Data";
    original.value = 42;
    original.price = 99.99;

    std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << &original << std::endl;
    std::cout << "  Name: " << original.name << std::endl;
    std::cout << "  Value: " << original.value << std::endl;
    std::cout << "  Price: " << original.price << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized (uintptr_t): " << serialized << std::endl;
    std::cout << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "  Address: " << deserialized << std::endl;
    std::cout << "  Name: " << deserialized->name << std::endl;
    std::cout << "  Value: " << deserialized->value << std::endl;
    std::cout << "  Price: " << deserialized->price << std::endl;
    std::cout << std::endl;

    if (deserialized == &original)
        std::cout << "✓ Success: Pointers are equal!" << std::endl;
    else
        std::cout << "✗ Error: Pointers are different!" << std::endl;

    return 0;
}
