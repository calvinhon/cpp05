#include "AForm.hpp"

AForm::AForm():
    _name("Useless document"),
    _reqGradeToSign(150),
    _reqGradeToExec(150),
    _signed(0) {}

AForm::AForm(const std::string& name, const int signGrade, const int execGrade):
    _name(name),
    _reqGradeToSign(signGrade),
    _reqGradeToExec(execGrade),
    _signed(0) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    }

AForm::AForm(const AForm& src):
    _name(src._name),
    _reqGradeToSign(src._reqGradeToSign),
    _reqGradeToExec(src._reqGradeToExec),
    _signed(src._signed) {}

AForm& AForm::operator=(const AForm& src) {
    if (this != &src)
        _signed = src._signed;
    return *this;
}

AForm::~AForm() {}

const std::string&	AForm::getName() const { return _name; }

int	AForm::getSignGrade() const { return _reqGradeToSign; }

int	AForm::getExecGrade() const { return _reqGradeToExec; }

int	AForm::getSignedStatus() const { return _signed; }

void	AForm::beSigned(const Bureaucrat& b) {
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

void AForm::execute(const Bureaucrat& executor) const {
    if (!_signed)
        throw UnsignedException();
    if (executor.getGrade() > _reqGradeToExec)
        throw GradeTooLowException();
    std::cout << executor.getName() << " executed " << _name << std::endl;
    action();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Exception caught: grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Exception caught: grade too low!";
}

const char* AForm::UnsignedException::what() const throw() {
    return "Exception caught: form is unsigned!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << ", required sign grade " << f.getSignGrade()
        << ", required execute grade " << f.getExecGrade()
		<< ", signed? " << f.getSignedStatus() << ".";
    return os;
}