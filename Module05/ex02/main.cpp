#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
// #include "Form.hpp"
/*
Exercise about errors and inheritance.
*/
int	main(void)
{
	Bureaucrat	tom("Tom");

	std::cout << "--------------\nTest Shruberry\n--------------" << std::endl;
	{
		try {
			std::cout << "Test not signed." << std::endl;
			ShrubberyCreationForm tree("amazon");
			std::cout << tree << std::endl;
			tree.execute(tom);
			tom.setGrade(50);
			tom.signForm(tree);
		}
		catch (std::exception& e) {
			std::cout << "catched: ";
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\nTest signed." << std::endl;
			ShrubberyCreationForm tree("amazon");
			std::cout << tree << std::endl;
			tom.setGrade(50);
			tom.signForm(tree);
			tree.execute(tom);
		}
		catch (std::exception& e) {
			std::cout << "catched: ";
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n\n--------------\nTest Robotomy\n--------------" << std::endl;
	{
		try {
			std::cout << "Test not signed." << std::endl;
			RobotomyRequestForm suspect("Suspect");
			std::cout << suspect << std::endl;
			suspect.execute(tom);
			tom.setGrade(50);
			tom.signForm(suspect);
		}
		catch (std::exception& e) {
			std::cout << "catched: ";
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\nTest signed." << std::endl;
			RobotomyRequestForm suspect("Suspect");
			std::cout << suspect << std::endl;
			tom.setGrade(50);
			tom.signForm(suspect);
			suspect.execute(tom);
		}
		catch (std::exception& e) {
			std::cout << "catched: ";
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n\n--------------\nTest Presidential\n--------------" << std::endl;
	{
		try {
			std::cout << "Test not signed." << std::endl;
			PresidentialPardonForm khan("Genghis");
			std::cout << khan << std::endl;
			khan.execute(tom);
			tom.setGrade(50);
			tom.signForm(khan);
		}
		catch (std::exception& e) {
			std::cout << "catched: ";
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\nTest signed." << std::endl;
			PresidentialPardonForm khan("Genghis");
			std::cout << khan << std::endl;
			tom.setGrade(1);
			tom.signForm(khan);
			khan.execute(tom);
		}
		catch (std::exception& e) {
			std::cout << "catched: ";
			std::cout << e.what() << std::endl;
		}
	}


}