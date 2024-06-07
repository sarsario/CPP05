#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this = src;
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    if (this != &src)
    {
        this->_name = src.getName();
        this->_grade = src.getGrade();
    }
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
    return *this;
}