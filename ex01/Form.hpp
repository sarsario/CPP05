#ifndef FORM_H
#define FORM_H

#define OKGREEN "\033[92m"
#define NOKRED "\033[91m"
#define RESET "\033[0m"

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
  public:
    Form();
    Form(std::string const name, int const signGrade, int const execGrade);
    Form(Form const &src);
    Form &operator=(Form const &src);
    ~Form();

    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

    void beSigned(Bureaucrat &bureaucrat);

  private:
    std::string const _name;
    bool _signed;
    int const _signGrade;
    int const _execGrade;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif