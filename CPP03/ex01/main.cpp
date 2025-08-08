#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== SCAVTRAP BATTLE BEGINS ===" << std::endl;

    ScavTrap alpha("Alpha");
    ScavTrap bravo("Bravo");

    std::cout << "\n--- Alpha enters Gate Keeper mode ---" << std::endl;
    alpha.guardGate();

    std::cout << "\n--- Bravo enters Gate Keeper mode ---" << std::endl;
    bravo.guardGate();

    std::cout << "\n=== FIGHT STARTS ===\n" << std::endl;

    for (int round = 1; round <= 5; ++round)
    {
        std::cout << "[Round " << round << "]" << std::endl;

        alpha.attack("Bravo");
        bravo.takeDamage(20);

        bravo.attack("Alpha");
        alpha.takeDamage(20);

        if (round % 2 == 0)
        {
            std::cout << "\nAlpha repairs!" << std::endl;
            alpha.beRepaired(10);

            std::cout << "Bravo repairs!" << std::endl;
            bravo.beRepaired(10);
        }

        std::cout << std::endl;
    }

    std::cout << "=== FINISHING MOVE ===" << std::endl;

    alpha.attack("Bravo");
    bravo.takeDamage(50);

    bravo.attack("Alpha");
    alpha.takeDamage(80);

    std::cout << "\n=== BATTLE ENDS ===" << std::endl;

    return 0;
}
