/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:13 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/15 18:05:45 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& tocopy) {
	*this = tocopy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& tocopy) {
	(void)tocopy;
	return (*this);
}

bool	isInt(const std::string& str){
	for (int i = (str[0] == '+') || (str[0] == '-');
			str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);	
	}
	return (true);
}

bool	isFloat(const std::string& str) {

	int			dot = str.find('.');
	std::string	nof = str.substr(dot);

	if (((size_t)dot == std::string::npos)
		|| (str[str.size() - 1] != 'f'))
		return (false);
	nof[nof.size() - 1] = 0;
	if (isInt(nof))
		return (true);
	return (false);
}

bool	isDouble(const std::string& str) {

	int	dot = str.find('.');
	
	if ((size_t)dot == std::string::npos)
		return (false);
	if (isInt(str.substr(dot)))
		return (true);
}

int inputType(const std::string& str)
{
	if (str.size() == 1)
		return (CHAR);
	if (isInt(str))
		return (INT);
	if (isFloat(str))
		return (FLOAT);
	if (isDouble(str))
		return (DOUBLE);
	return (IMPOSSIBLE);
}

// int numberType(const std::string& str)
// {
// 	int	dot = 0;
// 	int	f = 0;

//     for (int i = (str[0] == '+') || (str[0] == '-');
// 			str[i]; ++i) {
// 		dot += (str[i] == '.');
// 		f += (str[i] == 'f');
//         if ((!isdigit(str[i]) && (str[i] != '.') && (str[i] != 'f'))
// 			|| (dot > 1))
//             return (IMPOSSIBLE);
// 		if ((str[i] == 'f' && i != (int)(str.size() - 1))
// 			|| (str[i] == '.' && i == (int)(str.size() - 1)))
//             return (IMPOSSIBLE);
//     }
// 	// if ()
//     return (dot + f + 1);
// }

template<typename T>
void	printAll(T print)
{
	std::cout << "char: ";
	if (print > 31 && print < 127)
		std::cout << "'" << static_cast<char>(print) << "'" << std::endl;
	else
		std::cout << "Not a Character." << std::endl;
	std::cout << "int: " << static_cast<int>(print) << std::endl;
	std::cout	<< "float: " << std::fixed << std::setprecision(1)
				<< static_cast<float>(print) << "f" << std::endl;
	std::cout	<< "double: " << std::fixed << std::setprecision(1)
				<< static_cast<double>(print) << std::endl;
}

/*
Int overflow - breaks all
float overflow - breaks int, double
double overflow - breaks int, double
*/

void	ScalarConverter::convert(const std::string convert) {
	// int	type;

	// if (convert.size() == 1)
	// 	type = CHAR;
	// else
	// 	type = numberType(convert);
	switch (inputType(convert)) {
	case CHAR:
		printAll<char>(convert[0]);
		break;
	case INT:
		printAll<int>(std::atoi(convert.c_str()));
		break;
	case FLOAT:
		printAll<float>(std::atof(convert.c_str()));
		break;
	case DOUBLE:
		printAll<double>(std::atof(convert.c_str()));
		break;
	default:
		std::cout << "Impossible Conversion." << std::endl;
	}
	
}
