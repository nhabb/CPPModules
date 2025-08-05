#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    std::cout << "\n-- Round 1 --" << std::endl;
    a.attack("Bravo");
    b.takeDamage(0); // a has 0 attackDamage by default

    std::cout << "\n-- Upgrading Alpha's Attack --" << std::endl;
    // Simulate setting attack damage (should ideally have a setter)
    for (int i = 0; i < 5; ++i)
    {
        a.attack("Bravo");
        b.takeDamage(1);
    }

    std::cout << "\n-- Bravo Repairs --" << std::endl;
    b.beRepaired(3);

    std::cout << "\n-- Depleting Alpha's Energy --" << std::endl;
    for (int i = 0; i < 10; ++i)
        a.attack("Bravo"); // eventually will say no energy

    std::cout << "\n-- Bravo Takes Lethal Damage --" << std::endl;
    b.takeDamage(100);

    std::cout << "\n-- Bravo Tries to Act Dead --" << std::endl;
    b.attack("Alpha");
    b.beRepaired(10);

    std::cout << "\n-- Destruction --" << std::endl;
    return 0;
}
