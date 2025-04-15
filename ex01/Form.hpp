#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
    public:
		Form();
		Form(const std::string& name, const int signGrade, const int execGrade);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		void	beSigned(const Bureaucrat& b);

		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

    private:
        const std::string	_name;
        bool                _signed;
		const int			_reqGradeToSign;
		const int			_reqGradeToExec;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif