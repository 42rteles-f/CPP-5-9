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

bool	isDouble(std::string str) {

	size_t	dot = str.find('.');

	if (dot == std::string::npos)
		return (false);
	str[dot] = 0;
	if (!isInt(str) || !std::isdigit(str[dot + 1]) || !isInt(str.substr(dot + 1)))
		return (false);
	return (true);
}

bool	isFloat(std::string str) {

	if (str[str.size() - 1] != 'f')
		return (false);
	str[str.size() - 1] = 0;
	if (isDouble(str))
		return (true);
	return (false);
}

bool	isOverflow(std::string str, int type) {

	long long	number = std::atoll(str.c_str());

	if (type == CHAR && (number > CHAR_MAX || number < CHAR_MIN))
		return (true);
	if (type == INT && (number > INT_MAX || number < INT_MIN))
		return (true);
	if (type == FLOAT && (number > FLT_MAX || number < FLT_MIN))
		return (true);
	if (type == DOUBLE && (number > DBL_MAX || number < DBL_MIN))
		return (true);
	return (false);
}

int inputType(const std::string& str)
{
	if (str.empty())
		return (IMPOSSIBLE);
	if (str.size() == 1)
		return (isOverflow(str, CHAR) ? OVERFLOW : CHAR);
	if (isInt(str))
		return (isOverflow(str, INT) ? OVERFLOW : INT);
	if (isFloat(str))
		return (isOverflow(str, FLOAT) ? OVERFLOW : FLOAT);
	if (isDouble(str))
		return (isOverflow(str, DOUBLE) ? OVERFLOW : DOUBLE);
	return (IMPOSSIBLE);
}

template<typename T>
void	printAll(T print)
{
	std::cout << "char: ";
	if (print > 31 && print < 127)
		std::cout << "'" << static_cast<char>(print) << "'" << std::endl;
	else
		std::cout << "Not a Character." << std::endl;

	if (print <= INT_MAX && print >= INT_MIN)
		std::cout << "int: " << static_cast<int>(print) << std::endl;
	else
		std::cout << "int: Conversion Overflow." << std::endl;

	std::cout	<< "float: " << static_cast<float>(print);
	if ((static_cast<long long>(print * 10) % 10) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(print);
	if ((static_cast<long long>(print * 10) % 10) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert(const std::string convert) {

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
		case OVERFLOW:
			std::cout << "Overflow ";
			// fall through
		default:
			std::cout << "Impossible Conversion." << std::endl;
	}
}
