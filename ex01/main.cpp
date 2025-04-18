#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n\033[36m>>> Valid Bureaucrat and Form:\033[0m" << std::endl;
    try {
        Bureaucrat alice("Alice", 50);
        Form formA("FormA", 75, 100);
        std::cout << alice << std::endl;
        std::cout << formA << std::endl;
        formA.beSigned(alice);
        std::cout << formA << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[36m>>> Bureaucrat grade too low to sign:\033[0m" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form formB("FormB", 50, 100);
        std::cout << bob << std::endl;
        std::cout << formB << std::endl;
        formB.beSigned(bob);
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[36m>>> Invalid Form construction:\033[0m" << std::endl;
    try {
        Form formInvalid("InvalidForm", 0, 160);
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[36m>>> Invalid Form construction:\033[0m" << std::endl;
    try {
        Form formInvalid2("InvalidForm2", 5, 160);
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n";
    return 0;
}