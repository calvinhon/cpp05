#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

    std::cout << "\n\033[36m>>> Valid Form:" << "\033[0m" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* scf;
        scf = someRandomIntern.makeForm("SCF", "mountain chalet");
        Bureaucrat alice("Alice", 25);
        std::cout << alice << std::endl;
        std::cout << *scf << std::endl;
        scf->beSigned(alice);
        scf->execute(alice);
        std::cout << std::endl;

        AForm* rrf;
        rrf = someRandomIntern.makeForm("RRF", "R2D2");
        Bureaucrat mhat("Mad Hatter", 2);
        Bureaucrat bee = mhat;
        std::cout << mhat << std::endl;
        std::cout << *rrf << std::endl;
        rrf->beSigned(alice);
        rrf->execute(mhat);
        std::cout << std::endl;

        AForm* ppf;
        ppf = someRandomIntern.makeForm("PPF", "Mr. Beeblebrox");
        std::cout << *ppf << std::endl;
        ppf->beSigned(alice);
        ppf->execute(mhat);
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[36m>>> Invalid Form:" << "\033[0m" << std::endl;
    try {
        Intern someRandomIntern;
        Bureaucrat alice("Alice", 25);
        
        AForm* randomForm;
        randomForm = someRandomIntern.makeForm("randomForm", "Mr. Beeblebrox");
        std::cout << *randomForm << std::endl;
        randomForm->beSigned(alice);
        randomForm->execute(alice);
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n";
    return 0;
}