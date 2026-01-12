#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <stdint.h>
#include <string>

struct Data {
    std::string name;
    int value;
    double price;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};



#endif