#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern {
    public:
        Intern();
        ~Intern();

        AForm* makeForm(const std::string& name, const std::string& target);
    
        class FormDoesNotExist: public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        Intern(const Intern& src);
        Intern& operator=(const Intern& src);
};

#endif