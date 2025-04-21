#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm* createSCF(const std::string& target) { return new ShrubberyCreationForm(target); }
AForm* createRRF(const std::string& target) { return new RobotomyRequestForm(target); }
AForm* createPPF(const std::string& target) { return new PresidentialPardonForm(target); }

Intern::Intern(): _formCount(0) {
    for (int i = 0; i < 10; ++i)
        _createdForms[i] = NULL;
}

Intern::Intern(const Intern& src):
    _formCount(src._formCount) {
    for (int i = 0; i < 10; ++i)
        _createdForms[i] = (i < src._formCount && src._createdForms[i])
            ? src._createdForms[i]->clone() : NULL;
}

Intern& Intern::operator=(const Intern& src) {
    for (int i = 0; i < _formCount; ++i)
        delete _createdForms[i];
    _formCount = src._formCount;
    for (int i = 0; i < 10; ++i)
        _createdForms[i] = (i < src._formCount && src._createdForms[i])
            ? src._createdForms[i]->clone() : NULL;
    return *this;
}

Intern::~Intern() {
    for (int i = 0; i < _formCount; ++i)
        delete _createdForms[i];
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    std::string names[3] = {
        "SCF", "RRF", "PPF"
    };
    AForm* (*creators[3])(const std::string&) = {
        &createSCF, &createRRF, &createPPF
    };
    for (int i = 0; i < 3; ++i) {
        if (name == names[i]) {
            if (_formCount < 10) {
                AForm* form = creators[i](target);
                _createdForms[_formCount++] = form;
                std::cout << "\033[32mIntern creates " << name << "\033[0m" << std::endl;
                return form;
            }
            throw FormOverload();
        }
    }
    std::cout << "Intern couldn't find the form: " << name << std::endl;
    throw FormDoesNotExist();
}

const char* Intern::FormDoesNotExist::what() const throw() {
    return "Exception caught: form does not exist!";
}

const char* Intern::FormOverload::what() const throw() {
    return "Exception caught: intern can only create up to 10 forms!";
}
