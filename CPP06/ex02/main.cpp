#include <iostream>
#include "identify.hpp"

int main() {
    Base* p = generate();
    identify(p);
    delete p;
    return 0;
}
