#ifndef AFORM_H
#define AFORM_H

#define LIGHT_BLUE "\033[94m"
#define OKGREEN "\033[92m"
#define NOKRED "\033[91m"
#define RESET "\033[0m"

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
  public:
    virtual ~AForm();

    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class AssignationException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class UnsignedFormException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

  protected:
    AForm();
    AForm(std::string const name, int const signGrade, int const execGrade);
    AForm(AForm const &src);
    AForm &operator=(AForm const &src);

  private:
    std::string const _name;
    bool _signed;
    int const _signGrade;
    int const _execGrade;
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif