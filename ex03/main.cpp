#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
       Intern stan;
       Bureaucrat junior("junior", 150);
       Bureaucrat engineer("engineer", 45);
       Bureaucrat president("president", 1);
       AForm *tree = stan.makeForm("tree", "parking");

        junior.signForm(*tree);
        engineer.signForm(*tree);
        junior.executeForm(*tree);
        engineer.executeForm(*tree);
        AForm *workVisa = stan.makeForm("working visa", "junior");
        if (workVisa)
        {
            engineer.signForm(*workVisa);
            engineer.executeForm(*workVisa);
            delete workVisa;
        }
        delete tree;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}