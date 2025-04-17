#include "Bureaucrat.hpp"

int main() {

    std::cout << "\n\033[36m>>> Valid Bureaucrat and Decrement / Increment:\033[0m" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        std::cout << "Before: " << bob << std::endl;
        bob.decrementGrade();
        std::cout << "After: " << bob << std::endl;
        
        Bureaucrat sarah("Sarah", 150);
        std::cout << "Before: " << sarah << std::endl;
        sarah.incrementGrade();
        std::cout << "After: " << sarah << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[36m>>> Invalid Bureaucrat:\033[0m" << std::endl;
    try {
        Bureaucrat jake("Jake", 200);
        Bureaucrat blake("Blake", 0);
    } catch (const std::exception& e) {
        std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }


    std::cout << "\n\033[36m>>> Invalid Decrement / Increment:\033[0m" << std::endl;
    try {
        Bureaucrat joy("Joy", 1);
        std::cout << "Before: " << joy << std::endl;
        joy.incrementGrade();
        std::cout << "After: "  << joy << std::endl;

        Bureaucrat ash("Ash", 150);
        std::cout << "Before: " << ash << std::endl;
        ash.decrementGrade();
        std::cout << "After: "  << ash << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n";
    return 0;
}