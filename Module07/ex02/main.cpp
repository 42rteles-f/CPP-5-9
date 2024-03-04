#include <iostream>
#include "Array.hpp"

int	main(void)
{
	Array<int>	test(10);

	test[5] = 5;
	std::cout << test[5] << std::endl;
}