#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

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

    class GradeTooHighException: public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException: public std::exception
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

#endif