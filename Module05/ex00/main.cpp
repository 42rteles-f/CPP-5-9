#include "Bureaucrat.hpp"

/*
This exercise is designed to showcase the throw errors.
It should throw errors when changing the grade manually, or when using the increase/decrease methods.
It should also contain a overload of the <<operator


Declaring Custom exception Within the Class:
Small Projects or Specific Exceptions: 
*/
int	main(void)
{
	Bureaucrat	tom;

	tom.setName("Tom");
	try {
		tom.setGrade(0);
	}
	catch (std::exception& event) {
		std::cerr << "test grade 0" << std::endl;
		std::cerr << event.what() << std::endl;
		std::cerr << std::endl;
	}
	try {
		tom.setGrade(151);
	}
	catch (std::exception& event) {
		std::cerr << "test grade 151" << std::endl;
		std::cerr << event.what() << std::endl;
		std::cerr << std::endl;
	}
	try {
		tom.setGrade(1);
		tom.increaseGrade();
	}
	catch (std::exception& event) {
		std::cerr << "test increase" << std::endl;
		std::cerr << event.what() << std::endl;
		std::cerr << std::endl;
	}
	try {
		tom.setGrade(150);
		tom.decreaseGrade();
	}
	catch (std::exception& event) {
		std::cerr << "test decrease" << std::endl;
		std::cerr << event.what() << std::endl;
	}
	std::cout << tom << std::endl;
}