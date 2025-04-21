#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
    public:
		AForm(const std::string& name, const int signGrade, const int execGrade);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm();

		const std::string&	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		int					getSignedStatus() const;
		void				beSigned(const Bureaucrat& b);
		void				execute(const Bureaucrat& executor) const;
		virtual AForm*		clone() const = 0;

		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class UnsignedException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

	protected:
		virtual void	action() const = 0;

    private:
		AForm();
        const std::string	_name;
		const int			_reqGradeToSign;
		const int			_reqGradeToExec;
        bool                _signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif