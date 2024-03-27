#include "Bureaucrat.hpp"
#include "Intern.hpp"
// #include "Form.hpp"
/*
missing tests.

*/
int	main(void)
{
	Bureaucrat	tom("Tom");
	Intern		slave;
	AForm		*form = NULL;

	try {
		std::cout << "\n---------\nError Test\n---------" << std::endl;
		tom.setGrade(1);
		form = slave.makeForm(" creation", "amazon");
		std::cout << *form << std::endl;
		tom.signForm(*form);
		form->execute(tom);
		delete (form);
	}
	catch (std::exception& e) {
		std::cout << "catch: " << e.what() << std::endl;
	}
	try {
		std::cout << "\n---------\nRobotomy Test\n---------" << std::endl;
		tom.setGrade(1);
		form = slave.makeForm("robotomy request", "suspect");
		std::cout << *form << std::endl;
		tom.signForm(*form);
		form->execute(tom);
		delete (form);
	}
	catch (std::exception& e) {
		std::cout << "catch: " << e.what() << std::endl;
	}
	try {
		std::cout << "\n---------\nShruberry Test\n---------" << std::endl;
		tom.setGrade(1);
		form = slave.makeForm("shruberry creation", "amazon");
		std::cout << *form << std::endl;
		tom.signForm(*form);
		form->execute(tom);
		delete (form);
	}
	catch (std::exception& e) {
		std::cout << "catch: " << e.what() << std::endl;
	}
	try {
		std::cout << "\n---------\nPresidential Test\n---------" << std::endl;
		tom.setGrade(1);
		form = slave.makeForm("presidential pardon", "khan");
		std::cout << *form << std::endl;
		tom.signForm(*form);
		form->execute(tom);
		delete (form);
	}
	catch (std::exception& e) {
		std::cout << "catch: " << e.what() << std::endl;
	}
	std::cout << "\n" << std::endl;
}