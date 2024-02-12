#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "Form.hpp"
/*
missing tests.

*/
int	main(void)
{
	Bureaucrat	tom;
	ShrubberyCreationForm tree("amazon");	

	tom.setGrade(150);
	tom.setName("tom");
	try {
		tree.execute(tom);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}