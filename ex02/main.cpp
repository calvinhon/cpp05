#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    std::cout << "\n\033[36m>>> Valid Bureaucrat and Form:" << "\033[0m" << std::endl;
    try {
        Bureaucrat alice("Alice", 25);
        ShrubberyCreationForm formS("mountain chalet");
        std::cout << alice << std::endl;
        std::cout << formS << std::endl;
        formS.beSigned(alice);
        formS.execute(alice);
        std::cout << std::endl;

        RobotomyRequestForm formR("R2D2");
        Bureaucrat mhat("Mad Hatter", 2);
        Bureaucrat bee = mhat;
        std::cout << mhat << std::endl;
        std::cout << formR << std::endl;
        formR.beSigned(alice);
        formR.execute(mhat);
        std::cout << std::endl;

        PresidentialPardonForm formP("Mr. Beeblebrox");
        std::cout << formP << std::endl;
        formP.beSigned(alice);
        formP.execute(mhat);
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[36m>>> Unsigned:" << "\033[0m" << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        PresidentialPardonForm formB("office monkey");
        std::cout << bob << std::endl;
        formB.execute(bob);
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[36m>>> Execute grade too low:" << "\033[0m" << std::endl;
    try {
        Bureaucrat sarah("Sarah", 150);
        Bureaucrat jim("Jim", 1);
        ShrubberyCreationForm formC("lake house");
        formC.beSigned(jim);
        sarah.executeForm(formC);
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[36m>>> Polymorphism with base pointer:" << "\033[0m" << std::endl;
    try {
        AForm* form = new PresidentialPardonForm("Criminal");
        Bureaucrat zaphod("Zaphod", 1);
        form->beSigned(zaphod);
        zaphod.executeForm(*form);
        delete form;
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n";
    return 0;
}