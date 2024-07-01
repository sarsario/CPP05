#pragma once

#include "AForm.hpp"
#define GREY "\033[90m"

class RobotomyRequestForm : public AForm
{
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor) const;

  private:
    std::string _target;
};
