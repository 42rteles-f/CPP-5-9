/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:13 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/05 17:47:00 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
_target("")
{ std::cout << "PresidentialPardonForm Default Constructor called." << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(std::string target):
_target(target), AForm(, 145, 137)
{ std::cout << "PresidentialPardonForm Default Constructor called." << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& tocopy)
{
	std::cout << "PresidentialPardonForm Copy Constructor called." << std::endl;
	*this = tocopy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{ std::cout << "PresidentialPardonForm Destructor called." << std::endl; }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& tocopy) {
	if (this == &tocopy)
		return (*this);
	asdasd;
	/*
	to do;
	*/
	return (*this);
}
