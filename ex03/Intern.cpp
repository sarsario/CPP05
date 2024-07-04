#include "Intern.hpp"

Intern::Intern()
{
    std::cout << YELLOW << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(Intern const &src)
{
    std::cout << YELLOW << "Intern copy constructor called" << RESET << std::endl;
    *this = src;
}

Intern &Intern::operator=(Intern const &src)
{
    std::cout << YELLOW << "Intern assignation operator called" << RESET << std::endl;
    *this = src;
    return *this;
}

Intern::~Intern()
{
    std::cout << YELLOW << "Intern destructor called" << RESET << std::endl;
}

static AForm *makeShrubberyForm(std::string const target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomyForm(std::string const target)
{
    return new RobotomyRequestForm(target);
}
static AForm *makePresidentialForm(std::string const target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const formName, std::string const target)
{
    AForm *(*forms[])(std::string const target) = {&makeShrubberyForm, &makeRobotomyForm, &makePresidentialForm};
    std::string knownForms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm", "Shrubbery", "Robotomy", "Presidential", "shrubbery request", "robotomy request", "presidential request", "tree", "robot", "pardon"};

    for (int i = 0; i < (sizeof(knownForms) / sizeof(knownForms[0])); i++)
    {
        if (formName == knownForms[i])
        {
            std::cout << OKGREEN << "Intern creates " << formName << RESET << std::endl;
            return forms[i % 3](target);
        }
    }
    std::cout << NOKRED << "Intern cannot create form " << formName << RESET << std::endl;
    return NULL;
}