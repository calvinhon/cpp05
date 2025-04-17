#include "Form.hpp"

Form::Form(const std::string& name, const int signGrade, const int execGrade):
    _name(name),
    _reqGradeToSign(signGrade),
    _reqGradeToExec(execGrade),
    _signed(0) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    }

Form::Form(const Form& src):
    _name(src._name),
    _reqGradeToSign(src._reqGradeToSign),
    _reqGradeToExec(src._reqGradeToExec),
    _signed(src._signed) {}

Form& Form::operator=(const Form& src) {
    if (this != &src)
        _signed = src._signed;
    return *this;
}

Form::~Form() {}

const std::string&	Form::getName() const { return _name; }

int	Form::getSignGrade() const { return _reqGradeToSign; }

int	Form::getExecGrade() const { return _reqGradeToExec; }

void	Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= _reqGradeToSign) {
		std::cout << b.getName() << " signed " << _name << std::endl;
		_signed = 1;
	}
	else {
		std::cout << b.getName() << " couldn't sign " << _name
			<< " because grade is too low" << std::endl;
		throw GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Exception caught: grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Exception caught: grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << ", required sign grade " << f.getSignGrade()
        << ", required execute grade " << f.getExecGrade() << ".";
    return os;
}