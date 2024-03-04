#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

// Base * generate(void) {
// 	static	bool	seed = false;
// 	Base			*pointer = NULL;
// 	int				random = 0;;

// 	if (!seed) {
// 		std::srand(std::time(0));
// 		seed = true;
// 	}
// 	random = std::rand() % 10;
// 	if (random == 0) {
// 		pointer = new Base;
// 		std::cout << "Generate type: Base" << std::endl;
// 	}
// 	else if (random < 4) {
// 		pointer = new A;
// 		std::cout << "Generate type: A" << std::endl;
// 	}
// 	else if (random < 7) {
// 		pointer = new B;
// 		std::cout << "Generate type: B" << std::endl;
// 	}
// 	else {
// 		pointer = new C;
// 		std::cout << "Generate type: C" << std::endl;
// 	}
// 	return (pointer);
// }

Base * generate(void) {
	static	bool	seed = false;
	Base			*pointer = NULL;
	int				random = 0;

	if (!seed) {
		std::srand(std::time(0));
		seed = true;
	}
	random = std::rand() % 10;
	if (random < 4) {
		pointer = new A;
		std::cout << "Generate type: A" << std::endl;
	}
	else if (random < 7) {
		pointer = new B;
		std::cout << "Generate type: B" << std::endl;
	}
	else {
		pointer = new C;
		std::cout << "Generate type: C" << std::endl;
	}
	return (pointer);
}

void identify(Base* p) {
	char	type = 0;

	if (dynamic_cast<A*>(p) != NULL)
		type = 'A';
	else if (dynamic_cast<B*>(p) != NULL)
		type = 'B';
	else if (dynamic_cast<C*>(p) != NULL)
		type = 'C';
	else {
		std::cout << "Invalid Pointer" << std::endl;
		return ;
	}
	std::cout << "Pointer is of type <Class " << type << ">" << std::endl;
}

void identify(Base& p) {
	char	type = 0;

	try {
		(void)dynamic_cast<A&>(p);
		type = 'A';
	}
	catch (...)
	{
		try {
			(void)dynamic_cast<B&>(p);
			type = 'B';
		}
		catch (...)
		{
			try {
				(void)dynamic_cast<C&>(p);
				type = 'C';
			}
			catch (...) {
				std::cout << "Invalid Reference." << std::endl;
				return ;
			}
		}
	}
	std::cout << "Reference is of type <Class " << type << ">" << std::endl;
}

int	main(void)
{
	for (int i = 0; i < 10; i++)
	{
		{
			Base	*pointer = generate();
			if (!pointer)
				return (1);
			Base&	reference = *pointer;

			identify(pointer);
			identify(reference);
			delete (pointer);
			std::cout << std::endl;
		}
	}
	return (0);
}