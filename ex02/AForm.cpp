#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
    std::cout << LIGHT_BLUE << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string const name, int const signGrade, int const execGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << LIGHT_BLUE << "AForm parameterized constructor called" << RESET << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src)
    : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
    std::cout << LIGHT_BLUE << "AForm copy constructor called" << RESET << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
    std::cout << LIGHT_BLUE << "AForm assignation operator called" << RESET << std::endl;
    if (this != &src)
    {
        _signed = src._signed;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << LIGHT_BLUE << "AForm destructor called" << RESET << std::endl;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << OKGREEN << "signed" << RESET;
    else
        out << NOKRED << "not signed" << RESET;
    out << " and requires grade " << form.getSignGrade() << " to be signed and grade " << form.getExecGrade()
        << " to be executed";
}