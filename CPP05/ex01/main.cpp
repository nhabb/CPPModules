#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat b1("Alice", 50);
    Bureaucrat b2("Bob", 1);
    Bureaucrat b3("Charlie", 150);
    Bureaucrat b4("Dave", 149);

    Form f1("TaxForm", 75, 100);
    Form f2("PassportForm", 10, 20);
    Form f3("LicenseForm", 150, 150);
    Form f4("SecretForm", 1, 1);

    std::cout << f1;
    std::cout << f2;
    std::cout << f3;
    std::cout << f4;

    b1.signForm(f1);
    b2.signForm(f1);
    b3.signForm(f3);
    b4.signForm(f3);
    b4.signForm(f2);
    b1.signForm(f4);

    return 0;
}
