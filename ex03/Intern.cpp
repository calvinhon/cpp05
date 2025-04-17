#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm* createSCF(const std::string& target) { return new ShrubberyCreationForm(target); }
AForm* createRRF(const std::string& target) { return new RobotomyRequestForm(target); }
AForm* createPPF(const std::string& target) { return new PresidentialPardonForm(target); }

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    std::string names[3] = {
        "SCF", "RRF", "PPF"
    };
    AForm* (*creators[3])(const std::string&) = {
        &createSCF, &createRRF, &createPPF
    };
    for (int i = 0; i < 3; ++i) {
        if (name == names[i]) {
            std::cout << "\033[32mIntern creates " << name << "\033[0m" << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Intern couldn't find the form: " << name << std::endl;
    throw FormDoesNotExist();
}

const char* Intern::FormDoesNotExist::what() const throw() {
    return "Exception caught: form does not exist!";
}
