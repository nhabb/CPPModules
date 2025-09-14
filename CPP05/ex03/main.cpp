#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* unknown;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Fry");
    unknown = someRandomIntern.makeForm("unknown form", "Nobody");

    if (rrf) delete rrf;
    if (scf) delete scf;
    if (ppf) delete ppf;
    if (unknown) delete unknown;

    return 0;
}