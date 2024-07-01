#pragma once

#include "AForm.hpp"
#include <fstream>
#define LIGHT_RED "\033[91m"

class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;

  private:
    std::string _target;
};