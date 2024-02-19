#include "ScalarConverter.hpp"

int	main(int ac, char **args)
{
	if (ac != 2)
		return (0);
    ScalarConverter::convert(args[1]);

}