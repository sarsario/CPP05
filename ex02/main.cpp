#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat president("president", 1);
        Bureaucrat lead_engineer("lead_engineer", 30);
        Bureaucrat engineer("engineer", 50);
        Bureaucrat recruter("recruter", 75);
        Bureaucrat botanist("botanist", 100);
        Bureaucrat intern("intern", 150);

        ShrubberyCreationForm shrubbery("front_yard");
        RobotomyRequestForm robotomy("recruter");
        PresidentialPardonForm pardon("lead_engineer");

        std::cout << std::endl;
        intern.signForm(shrubbery);
        intern.executeForm(shrubbery);

        std::cout << std::endl;
        botanist.executeForm(shrubbery);
        botanist.signForm(shrubbery);
        botanist.executeForm(shrubbery);

        std::cout << std::endl;
        recruter.signForm(robotomy);
        recruter.executeForm(robotomy);

        std::cout << std::endl;
        lead_engineer.signForm(pardon);
        lead_engineer.executeForm(pardon);

        std::cout << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}