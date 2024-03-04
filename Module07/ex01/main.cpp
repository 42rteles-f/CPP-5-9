#include <iostream>
#include "iter.hpp"

class Test {
	public:
		std::string name;
		Test() {name = "none";};
};

void	intFunction(int& number) {
	number++;
}

void	charFunction(char& byte) {
	byte--;
}

void	testFunction(Test& change) {
	change.name = "Raul";
}

void	classPrint(Test& print) {
	std::cout << print.name;
}

//Introduction to Template Manipulation.
int	main(void)
{
	int		int_a[5] = {1, 2, 3, 4, 5};
	char	char_a[11] = "helloworld";
	Test	test_a[15];

	::iter(int_a, 5, ::templatePrint);
	std::cout << std::endl;
	::iter(int_a, 5, intFunction);
	::iter(int_a, 5, ::templatePrint);
	std::cout << std::endl;

	::iter(char_a, 10, ::templatePrint);
	std::cout << std::endl;
	::iter(char_a, 10, charFunction);
	::iter(char_a, 10, ::templatePrint);
	std::cout << std::endl;

	::iter(test_a, 15, ::classPrint);
	std::cout << std::endl;
	::iter(test_a, 15, testFunction);
	::iter(test_a, 15, classPrint);
	std::cout << std::endl;
}