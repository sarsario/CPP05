#ifndef BUROCRAT_H
#define BUROCRAT_H

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
private:
	std::string const _name;
	int _grade;
};

#endif