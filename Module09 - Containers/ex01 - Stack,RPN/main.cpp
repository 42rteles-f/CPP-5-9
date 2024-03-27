#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2)
		return (0);
	// std::cout << "first" << std::endl;
	RPN::calculate(av[1]);
}