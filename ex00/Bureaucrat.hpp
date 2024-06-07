#ifndef BUROCRAT_H
#define BUROCRAT_H

#define ORANGE "\033[33m"
#define MAGENTA "\033[35m"
#define LIGHT_BLUE "\033[94m"
#define RESET "\033[0m"

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &src);
	~Bureaucrat();

	Bureaucrat(std::string const name, int grade);
	std::string getName() const;
	int getGrade() const;
	void promote();
	void demote();

	class GradeTooHighException: public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	std::string const _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif