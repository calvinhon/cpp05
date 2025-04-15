#include "Form.hpp"

Form::Form(): _reqGradeToSign(150), _reqGradeToExec(150) {}

Form::Form(const std::string& name, const int signGrade, const int execGrade):
    _name(name),
    _reqGradeToSign(signGrade),
    _reqGradeToExec(execGrade) {}

Form::Form(const Form& src):
    _name(src._name),
    _reqGradeToSign(src._reqGradeToSign),
    _reqGradeToExec(src._reqGradeToExec) {}

Form& Form::operator=(const Form& src) {
    if (this != &src)
        _name = src._name;
    return *this;
}

Form::~Form() {}

void	Form::beSigned(const Bureaucrat& b) {}
