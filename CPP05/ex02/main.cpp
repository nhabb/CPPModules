#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat boss("Boss", 1);           // Highest grade
        Bureaucrat intern("Intern", 150);     // Lowest grade

        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
        boss.signForm(shrub);
        boss.executeForm(shrub);

        std::cout << "\n--- Testing RobotomyRequestForm ---\n";
        boss.signForm(robot);
        boss.executeForm(robot);

        std::cout << "\n--- Testing PresidentialPardonForm ---\n";
        boss.signForm(pardon);
        boss.executeForm(pardon);

        std::cout << "\n--- Testing with Intern (should fail) ---\n";
        intern.signForm(shrub);
        intern.executeForm(shrub);

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
