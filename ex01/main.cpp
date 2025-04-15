#include "Bureaucrat.hpp"

int main() {

    std::cout << "\n>------------- Try block 1 -------------<" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        std::cout << bob << std::endl;
        
        Bureaucrat sarah("Sarah", 150);
        std::cout << "Before: " << sarah << std::endl;
        sarah.incrementGrade();
        std::cout << "After: "  << sarah << std::endl;

        Bureaucrat jimbo("Jimbo", 200);
        std::cout << jimbo << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n>------------- Try block 2 -------------<" << std::endl;
    try {
        Bureaucrat jake("Jake", 149);
        std::cout << "Before: " << jake << std::endl;
        jake.decrementGrade();
        std::cout << "After: "  << jake << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n>------------- Try block 3 -------------<" << std::endl;
    try {
        Bureaucrat joy("Joy", 1);
        std::cout << "Before: " << joy << std::endl;
        joy.incrementGrade();
        std::cout << "After: "  << joy << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n";
}