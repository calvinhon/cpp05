#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
  
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		class GradeTooLowException: public std::exception {
			public: 
				virtual const char *what() const throw();
		};

		class GradeTooHighException: public std::exception {
			public: 
				virtual const char *what() const throw();
		};

	private:
		Bureaucrat();
		const std::string	_name;
		int					_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif