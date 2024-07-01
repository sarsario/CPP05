#pragma once

#include "AForm.hpp"
#include <fstream>
#define PURPLE "\033[95m"

class ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;

  private:
    std::string _target;
};