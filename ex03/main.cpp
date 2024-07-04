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
        Bureaucrat lead_recruter("lead_recruter", 75);
        Bureaucrat botanist("botanist", 100);
        Bureaucrat intern("intern", 150);

        ShrubberyCreationForm shrubbery("front_yard");
        RobotomyRequestForm robotomy1("recruter");
        RobotomyRequestForm robotomy2("lead_recruter");
        PresidentialPardonForm pardon("lead_engineer");

        std::cout << std::endl;
        intern.signForm(shrubbery);
        intern.executeForm(shrubbery);

        std::cout << std::endl;
        botanist.executeForm(shrubbery);
        botanist.signForm(shrubbery);
        botanist.executeForm(shrubbery);

        std::cout << std::endl;
        recruter.signForm(robotomy1);
        recruter.executeForm(robotomy1);

        std::cout << std::endl;
        engineer.signForm(robotomy1);
        engineer.executeForm(robotomy1);

        std::cout << std::endl;
        lead_engineer.signForm(robotomy1);
        lead_engineer.executeForm(robotomy1);
        lead_engineer.signForm(robotomy2);
        lead_engineer.executeForm(robotomy2);

        std::cout << std::endl;
        lead_engineer.signForm(pardon);
        lead_engineer.executeForm(pardon);

        std::cout << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}