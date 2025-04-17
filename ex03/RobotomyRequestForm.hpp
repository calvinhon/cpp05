#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();

		void	action() const;

	private:
		RobotomyRequestForm();
		const std::string _target;
};

#endif