#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern& src);
        Intern& operator=(const Intern& src);
        ~Intern();

        AForm* makeForm(const std::string& name, const std::string& target);
    
        class FormDoesNotExist: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormOverload: public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        AForm*  _createdForms[10];
        int     _formCount;
};

#endif