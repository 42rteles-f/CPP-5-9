/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:13 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/14 14:47:56 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter():
{ std::cout << "ScalarConverter Default Constructor called." << std::endl; }

ScalarConverter::ScalarConverter(const ScalarConverter& tocopy)
{
	std::cout << "ScalarConverter Copy Constructor called." << std::endl;
	*this = tocopy;
}

ScalarConverter::~ScalarConverter()
{ std::cout << "ScalarConverter Destructor called." << std::endl; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& tocopy) {
	if (this == &tocopy)
		return (*this);
	asdasd;
	/*
	to do;
	*/
	return (*this);
}
