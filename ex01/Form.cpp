#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
    std::cout << LIGHT_BLUE << "Form " << _name << " created" << RESET << std::endl;
}

Form::Form(std::string const name, int const signGrade, int const execGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
    std::cout << LIGHT_BLUE << "Form " << _name << " created" << RESET << std::endl;
}

Form::Form(Form const &src)
    : _name(src.getName()), _signed(src.getSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
    *this = src;
}

Form &Form::operator=(Form const &src)
{
    if (this != &src)
        this->_signed = src.getSigned();
    std::cout << LIGHT_BLUE << "Form " << _name << " created" << RESET << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << LIGHT_BLUE << "Form " << _name << " destroyed" << RESET << std::endl;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getSignGrade() const
{
    return this->_signGrade;
}

int Form::getExecGrade() const
{
    return this->_execGrade;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSignGrade())
        throw Form::GradeTooLowException();
    this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "Form " << form.getName() << " is ";
    form.getSigned() ? out << OKGREEN << "signed" : out << NOKRED << "not signed";
    out << RESET << " and requires grade " << form.getSignGrade() << " to be signed and grade " << form.getExecGrade()
        << " to be executed";
    return out;
}