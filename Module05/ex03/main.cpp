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
	AForm		*form;

	try {
		tom.setGrade(1);
		form = slave.makeForm("shruberry creation", "amazon");
		tom.signForm(*form);
		form->execute(tom);
		free(form);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}