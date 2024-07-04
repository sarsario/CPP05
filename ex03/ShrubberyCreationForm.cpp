#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << PURPLE << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << PURPLE << "ShrubberyCreationForm parameterized constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target)
{
    std::cout << PURPLE << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    std::cout << PURPLE << "ShrubberyCreationForm assignation operator called" << RESET << std::endl;
    if (this != &src)
    {
        _target = src._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << PURPLE << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::UnsignedFormException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    std::ofstream file(_target + "_shrubbery");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file");
    file << "          &&& &&  & &&" << std::endl;
    file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
    file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    file << "     &&     \\|||" << std::endl;
    file << "             |||" << std::endl;
    file << "             |||" << std::endl;
    file << "             |||" << std::endl;
    file << "       , -=-~  .-^- _" << std::endl;
    file << "             `\" `\"" << std::endl;
    file.close();
}