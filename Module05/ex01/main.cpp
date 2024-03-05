#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
More throws exercises.
Throw where the code doesnt stop within a method.

*/
int	main(void)
{
	Bureaucrat	tom("Tom", 50);

	{
		std::cout << "Invalid Sign Grade test" << std::endl;
		try {
			std::cout << "Grade 0" << std::endl;
			Form	abc("abc", 0, 50);
			std::cout << abc << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "catch: " << e.what() << std::endl << std::endl;
		}
		try {
			std::cout << "Grade 151" << std::endl;
			Form	abc("abc", 151, 50);
			std::cout << abc << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "catch: " << e.what() << std::endl << std::endl;
		}
	std::cout << "-------------" << std::endl;
	}

	{
		std::cout << "Invalid Execute Grade test" << std::endl;
		try {
			std::cout << "Grade 0" << std::endl;
			Form	abc("abc", 50, 0);
			std::cout << abc << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "catch: " << e.what() << std::endl << std::endl;
		}
		try {
			std::cout << "Grade 151" << std::endl;
			Form	abc("abc", 50, 151);
			std::cout << abc << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "catch: " << e.what() << std::endl << std::endl;
		}
	std::cout << "-------------" << std::endl;
	}

	{
		std::cout << "Valid Grades Test" << std::endl;
		try {
			std::cout << "Grade 50, 50" << std::endl;
			Form	abc("abc", 50, 50);
			std::cout << abc << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "catch: " << e.what() << std::endl << std::endl;
		}
	std::cout << "-------------" << std::endl;
	}

	{
		std::cout << "Sign test" << std::endl;
		try {
			Form	abc("abc", 50, 50);
			std::cout << abc << std::endl;
			tom.signForm(abc);
			std::cout << abc << std::endl;
			std::cout << "-------------" << std::endl;
			Form	qwe("qwe", 49, 49);
			std::cout << qwe << std::endl;
			tom.signForm(qwe);
		}
		catch (const std::exception& e) {
			std::cout << "catch: " << e.what() << std::endl << std::endl;
		}
	std::cout << "-------------" << std::endl;
	}
	std::cout << tom << std::endl;
}