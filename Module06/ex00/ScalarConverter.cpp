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

bool	isOverflow(std::string str) {
	std::ostringstream stream;

    stream << std::atoll(str.c_str());
	if (stream.str() != str)
		return (true);
	return (false);
}

int inputType(const std::string& str)
{
	if (str.size() == 1)
		return (isOverflow(str) ? OVERFLOW : CHAR);
	if (isInt(str))
		return (isOverflow(str) ? OVERFLOW : INT);
	if (isFloat(str))
		return (isOverflow(str) ? OVERFLOW : FLOAT);
	if (isDouble(str))
		return (isOverflow(str) ? OVERFLOW : DOUBLE);
	return (IMPOSSIBLE);
}

template<typename T>
void	printAll(T print, long long size)
{
	std::cout << "char: ";
	if (size > 31 && size < 127)
		std::cout << "'" << static_cast<char>(print) << "'" << std::endl;
	else
		std::cout << "Not a Character." << std::endl;

	if (size < INT_MAX && size > INT_MIN)
		std::cout << "int: " << static_cast<int>(print) << std::endl;
	else
		std::cout << "int: Conversion Overflow." << std::endl;

	if (size < FLT_MAX && size > FLT_MIN) {
		std::cout	<< "float: " << std::fixed << std::setprecision(1)
					<< static_cast<float>(print) << "f" << std::endl;
	}
	else
		std::cout << "float: Conversion Overflow." << std::endl;

	if (size < DBL_MAX && size > DBL_MIN) {
		std::cout	<< "double: " << std::fixed << std::setprecision(1)
					<< static_cast<double>(print) << std::endl;
	}
	else
		std::cout << "double: Conversion Overflow." << std::endl;
}

void	ScalarConverter::convert(const std::string convert) {

	if (convert.empty())
		return ;
	switch (inputType(convert)) {
	case CHAR:
		printAll<char>(convert[0], std::atoll(convert.c_str()));
		break;
	case INT:
		printAll<int>(std::atoi(convert.c_str()), std::atoll(convert.c_str()));
		break;
	case FLOAT:
		printAll<float>(std::atof(convert.c_str()), std::atoll(convert.c_str()));
		break;
	case DOUBLE:
		printAll<double>(std::atof(convert.c_str()), std::atoll(convert.c_str()));
		break;
	case OVERFLOW:
		std::cout << "Overflow ";
		// fall through
	default:
		std::cout << "Impossible Conversion." << std::endl;
	}
}
