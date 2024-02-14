/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:13 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/14 17:00:10 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& tocopy) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& tocopy) {
	return (*this);
}

void	ScalarConverter::printChar(std::string convert)
{
	char	*print

	if (convert.size() < 5) {
		print
	}
	else
	005
}

void	ScalarConverter::printInt(std::string convert) {
	
}

void	ScalarConverter::printFloat(std::string convert) {
	
}

void	ScalarConverter::printDouble(std::string convert) {
	
}

template<typename T>
void	printAll(T print) {
	std::cout << static_cast<char>(print) << std::endl;
	std::cout << static_cast<int>(print) << std::endl;
	std::cout << static_cast<float>(print) << std::endl;
	std::cout << static_cast<double>(print) << std::endl;	
}

void	ScalarConverter::convert(const std::string convert) {
	double	converted;
	char	test;
	
	std::cout << static_cast<char>(converted) << std::endl;
	std::cout << static_cast<int>(converted) << std::endl;
	std::cout << static_cast<float>(converted) << std::endl;
	std::cout << static_cast<double>(converted) << std::endl;
	printChar(convert);
	printInt(convert);
	printFloat(convert);
	printDouble(convert);
	
	printAll(converted);
	printAll(test);
	
	sizeof(double);
	sizeof(int);
	sizeof(float);
	
}

/*
char
• int
• float
• double
*/
