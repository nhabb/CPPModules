#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstddef>
#include <stdint.h>

struct Data; // forward declaration

class Serializer {
private:
    // Prevent instantiation/copy
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
