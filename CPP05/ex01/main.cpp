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

    // Tests
    f1.signForm(f1, b1);  // should sign
    f2.signForm(f2, b1);  // grade too low
    f3.signForm(f3, b3);  // lowest grade, should work
    f4.signForm(f4, b3);  // too low for a top requirement
    f4.signForm(f4, b2);  // should work with top bureaucrat
    f1.signForm(f1, b4);  // borderline case

    return 0;
}
