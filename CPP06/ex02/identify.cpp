#include <iostream>
#include <cstdlib>
#include <ctime>
#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    // Seed once per run conservatively (ok if called multiple times)
    static bool seeded = false;
    if (!seeded) { std::srand(static_cast<unsigned int>(std::time(0))); seeded = true; }
    int r = std::rand() % 3;
    switch (r) {
        case 0: return new A();
        case 1: return new B();
        default: return new C();
    }
}

void identify(Base* p) {
    if (!p) { std::cout << "Pointer is null\n"; return; }
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
    } else {
        std::cout << "Unknown\n";
    }
}

void identify(Base& p) {
    // Must not use pointers here; rely on references and exceptions
    // dynamic_cast on references throws std::bad_cast on failure
    try { (void)dynamic_cast<A&>(p); std::cout << "A\n"; return; } catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B\n"; return; } catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C\n"; return; } catch (...) {}
    std::cout << "Unknown\n";
}
