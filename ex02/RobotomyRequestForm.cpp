#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
    AForm("RobotomyRequestForm", 72, 45),
    _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
    AForm(src) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
    if (this != &src)
       AForm::operator=(src);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::action() const {
    std::cout << "\033[32mBRRRRRRRRRRRRRRRRRRRRRRRR\nDRRRRRRRRRR-DRRRRRRRRRRR\nDZZZZZZZZZZZZZZZZZZZZZ\nRRRrrrrRRRRrrrrRRRRrrrr\nCHKKKKKKKKK-CHKKKKKKKKK\nZZZZZRRRRRRZZZZZRRRRRR\nVRRRRRR-VRRRRRR-VRRRRRR\nTKTKTKTKTKTK-TKTKTKTKTK" << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "attempted robotomy on " << _target << " has failed epically" << std::endl;
    std::cout << "\033[0m";
}
