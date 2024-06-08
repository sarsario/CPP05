#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat boss("CEO", 1);
        Form budget("Hiring budget form", 10, 5);
        boss.signForm(budget);
        std::cout << budget << std::endl;

        Bureaucrat intern("Intern Jack", 150);
        Form internship("Internship form", 100, 100);
        std::cout << internship << std::endl;
        intern.signForm(internship);
        boss.signForm(internship);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}