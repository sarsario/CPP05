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
       AForm *pardon = stan.makeForm("Presidential", "engineer");

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
        president.executeForm(*pardon);
        president.signForm(*pardon);
        president.executeForm(*pardon);
        delete tree;
        delete pardon;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}