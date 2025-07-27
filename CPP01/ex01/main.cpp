#include "Zombie.hpp"

void testNormalHorde() 
{
    std::cout << "\n[TEST] Normal Horde\n";
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "Walker");
    if (!horde) {
        std::cerr << "Failed to create horde.\n";
        return;
    }
    for (int i = 0; i < hordeSize; ++i)
        horde[i].Announce();
    delete[] horde;
}

void testZeroHorde() 
{
    std::cout << "\n[TEST] Zero-size Horde\n";
    Zombie* horde = zombieHorde(0, "Ghost");
    if (!horde)
        std::cout << "Passed: No zombies created for size 0.\n";
    else {
        std::cerr << "Failed: Expected nullptr for size 0.\n";
        delete[] horde;
    }
}

void testNegativeHorde() 
{
    std::cout << "\n[TEST] Negative-size Horde\n";
    Zombie* horde = zombieHorde(-3, "Specter");
    if (!horde)
        std::cout << "Passed: No zombies created for negative size.\n";
    else {
        std::cerr << "Failed: Expected nullptr for negative size.\n";
        delete[] horde;
    }
}

int main() {
    testNormalHorde();
    testZeroHorde();
    testNegativeHorde();
    return 0;
}



int main() 
{
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "Ghoul");
    if (!horde)
        return 1;
    for (int i = 0; i < hordeSize; ++i)
        horde[i].Announce();
    delete[] horde;
    return 0;
}