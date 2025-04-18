#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
    public:
		Form(const std::string& name, const int signGrade, const int execGrade);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		const std::string&	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		int					getSignedStatus() const;
		void				beSigned(const Bureaucrat& b);

		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

    private:
		Form();
        
		const std::string	_name;
		const int			_reqGradeToSign;
		const int			_reqGradeToExec;
        bool                _signed;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif