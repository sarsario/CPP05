#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#define MAGENTA "\033[35m"
#define LIGHT_BLUE "\033[94m"
#define OKGREEN "\033[92m"
#define NOKRED "\033[91m"
#define RESET "\033[0m"

#include "Form.hpp"
#include <iostream>

class Form;

class Bureaucrat
{
  public:
    Bureaucrat();
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(Bureaucrat const &src);
    ~Bureaucrat();

    Bureaucrat(std::string const name, int grade);
    std::string getName() const;
    int getGrade() const;
    void promote();
    void demote();

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

    void signForm(Form &form);

  private:
    std::string const _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif