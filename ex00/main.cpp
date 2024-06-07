#include "Bureaucrat.hpp"

int main()
{
    std::cout << LIGHT_BLUE << "Create and destroy" << std::endl;
    std::cout << "-----------------" << std::endl;
    try
    {
        Bureaucrat nameless;
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Bureaucrat doppelganger(intern);
        Bureaucrat clone = doppelganger;
        Bureaucrat failed_interview("Failed Interview", 151);
        Bureaucrat failed_overturn("Failed Overturn", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl << RESET;
    }
    std::cout << ORANGE << std::endl << "Promote and demote" << std::endl;
    std::cout << "-----------------" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Bureaucrat john("John", 50);
        Bureaucrat jane("Jane", 100);
        jane.promote();
        john.demote();
        boss.promote();
        intern.demote();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl << RESET;
    }
    std::cout << MAGENTA << std::endl << "Output" << std::endl;
    std::cout << "-----------------" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << RESET;
    return 0;
}