#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
    AForm("PresidentialPardonForm", 25, 5),
    _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src):
    AForm(src) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    if (this != &src)
       AForm::operator=(src);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::action() const {
    std::cout << "\033[32m" << _target << " has been pardoned by Zaphod Beeblebrox.\033[0m" << std::endl;
}

AForm* PresidentialPardonForm::clone() const {
    return new PresidentialPardonForm(_target);
}
