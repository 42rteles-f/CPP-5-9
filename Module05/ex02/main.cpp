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
	Bureaucrat	tom("Tom", 150);

	std::cout << "--------------\nTest Shruberry\n--------------" << std::endl;
	{
		try {
			ShrubberyCreationForm tree("amazon");
			std::cout << tree << std::endl;
			tom.executeForm(tree);
			tom.signForm(tree);
			tom.setGrade(1);
			tom.signForm(tree);
			tom.setGrade(150);
			tom.executeForm(tree);
			tom.setGrade(1);
			tom.executeForm(tree);
			tom.setGrade(150);
		}
		catch (std::exception& e) {
			std::cout << "catched: ";
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n\n--------------\nTest Robotomy\n--------------" << std::endl;
	{
		try {
			RobotomyRequestForm suspect("Suspect");
			std::cout << suspect << std::endl;
			tom.executeForm(suspect);
			tom.signForm(suspect);
			tom.setGrade(1);
			tom.signForm(suspect);
			tom.setGrade(150);
			tom.executeForm(suspect);
			tom.setGrade(1);
			tom.executeForm(suspect);
			tom.setGrade(150);
		}
		catch (std::exception& e) {
			std::cout << "catched: ";
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n\n--------------\nTest Presidential\n--------------" << std::endl;
	{
		try {
			PresidentialPardonForm genghis("Khan");
			std::cout << genghis << std::endl;
			tom.executeForm(genghis);
			tom.signForm(genghis);
			tom.setGrade(1);
			tom.signForm(genghis);
			tom.setGrade(150);
			tom.executeForm(genghis);
			tom.setGrade(1);
			tom.executeForm(genghis);
		}
		catch (std::exception& e) {
			std::cout << "catched: ";
			std::cout << e.what() << std::endl;
		}
	}

}