#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

static void printData(const char* prefix, const Data* d) {
    if (!d) { std::cout << prefix << " (null)\n"; return; }
    std::cout << prefix << " Data{id=" << d->id << ", name=\"" << d->name << "\", value=" << d->value << "}\n";
}

// Active demo: round-trip the same pointer (should be equal)
int main() {
    Data original(42, "example", 3.14159);

    printData("original:", &original);

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "serialized uintptr_t: " << raw << "\n";

    Data* roundtrip = Serializer::deserialize(raw);
    printData("deserialized:", roundtrip);

    std::cout << "same pointer? " << ( (roundtrip == &original) ? "yes" : "no" ) << "\n";

    return 0;
}

// Alternative demo (commented): serialize a different object and compare to original (should be not equal)
// int main() {
//     Data original(1, "alpha", 1.23);
//     Data other(2, "beta", 4.56);
//
//     printData("original:", &original);
//     printData("other:", &other);
//
//     // Serialize 'other' but compare to &original to demonstrate inequality
//     uintptr_t raw = Serializer::serialize(&other);
//     std::cout << "serialized uintptr_t (of other): " << raw << "\n";
//
//     Data* roundtrip = Serializer::deserialize(raw);
//     printData("deserialized:", roundtrip);
//
//     std::cout << "same pointer? " << ( (roundtrip == &original) ? "yes" : "no" ) << "\n";
//
//     return 0;
// }