#include "ScalarConverter.hpp"

/*
Exercise to learn about static_cast
Scalar types are types that hold a single value. Excluding classes and structures.
Its not instanciable due to its constructor being private
*/
int	main(int ac, char **args)
{
	if (ac != 2)
		return (0);
    ScalarConverter::convert(args[1]);
}