#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm(std::string const target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
    virtual ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;

  private:
    ShrubberyCreationForm();
    std::string const _target;
};