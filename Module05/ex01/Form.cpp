/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:13 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/05 17:47:00 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
{ std::cout << "Form Default Constructor called." << std::endl; }

Form::Form(const Form& tocopy)
{
	std::cout << "Form Copy Constructor called." << std::endl;
	*this = tocopy;
}

Form::~Form()
{ std::cout << "Form Destructor called." << std::endl; }

Form& Form::operator=(const Form& tocopy) {
	if (this == &tocopy)
		return (*this);
	/*
	to do;
	*/
	return (*this);
}
