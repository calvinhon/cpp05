#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
    AForm("ShrubberyForm", 145, 137),
    _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
    AForm(src) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    if (this != &src)
       AForm::operator=(src);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::action() const {
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
        std::cerr << "File creation failed" << std::endl;
    else {
        ofs << "       /\\\n";
        ofs << "      /**\\\n";
        ofs << "     /****\\\n";
        ofs << "    /******\\\n";
        ofs << "   /********\\\n";
        ofs << "       ||\n";
        ofs << "       ||\n";
        ofs.close();
    }
}
