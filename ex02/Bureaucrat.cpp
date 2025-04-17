#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade):
    _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src):
    _name(src._name),
    _grade(src._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    if (this != &src)
        _grade = src._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string&  Bureaucrat::getName() const {return _name;}

int   Bureaucrat::getGrade() const {return _grade;}

void    Bureaucrat::incrementGrade() {
    if (_grade > 1)
        _grade--;
    else
        throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

void    Bureaucrat::signForm(AForm& form) const {
    form.beSigned(*this);
}

void    Bureaucrat::executeForm(const AForm& form) const {
    if (_grade <= form.getExecGrade())
        form.execute(*this);
    else {
        std::cout << _name << " couldn't execute " << form.getName() << " because grade is too low" << std::endl;
        throw GradeTooLowException();
    }
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exception caught: Bureaucrat grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exception caught: Bureaucrat grade is too low!";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
