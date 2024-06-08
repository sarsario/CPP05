#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src.getName())
{
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    if (this != &src)
    {
        this->_grade = src.getGrade();
    }
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
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

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::promote()
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
    std::cout << *this << " has been promoted! Congratulation!" << std::endl;
}

void Bureaucrat::demote()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
    std::cout << *this << " has been demoted! Work harder!!" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void Bureaucrat::signForm(std::string const formName, bool const formSigned) const
{
    if (formSigned)
        std::cout << _name << " signed " << formName << std::endl;
    else
        std::cout << _name << " couln't sign " << formName << " because his grade is too low" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    return out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}