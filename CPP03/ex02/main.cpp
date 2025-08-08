#include "FragTrap.hpp"

int main()
{
    std::cout << "=== FRAGTRAP DEMO ===" << std::endl;
    //default constructor test
    FragTrap test;
    std::cout << "\n-- Creating FragTrap A --" << std::endl;
    FragTrap a("Alpha");

    std::cout << "\n-- Creating FragTrap B by Copying A --" << std::endl;
    FragTrap b(a);

    std::cout << "\n-- Creating FragTrap C and Assigning A to it --" << std::endl;
    FragTrap c;
    c = a;

    std::cout << "\n-- Alpha is Attacking a Target --" << std::endl;
    a.attack("Training Dummy");

    std::cout << "\n-- Bravo is Asking for High Fives --" << std::endl;
    b.highFivesGuys();

    std::cout << "\n-- Charlie Takes Damage and Repairs --" << std::endl;
    c.takeDamage(40);
    c.beRepaired(25);
    std::cout << "\n-- Battle Ending --" << std::endl;
    return 0;
}
