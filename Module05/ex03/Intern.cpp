/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:18:20 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/21 17:25:42 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm	*newShruberry(std::string target);
AForm	*newPresidential(std::string target);
AForm	*newRobotomy(std::string target);

Intern::Intern()
{
	functions[0] = newShruberry;
	functions[1] = newPresidential;
	functions[2] = newRobotomy;
	functions[3] = NULL;
	_cases[0] = (char *)"shruberry creation";
	_cases[1] = (char *)"presidential pardon";
	_cases[2] = (char *)"robotomy request";
	_cases[3] = NULL;
	std::cout << "Intern Default Constructor called." << std::endl; 
}

Intern::Intern(const Intern& tocopy)
{
	std::cout << "Intern Copy Constructor called." << std::endl;
	*this = tocopy;
}

Intern::~Intern()
{ std::cout << "Intern Destructor called." << std::endl; }

Intern& Intern::operator=(const Intern& tocopy) {
	if (this == &tocopy)
		return (*this);
	return (*this);
}

AForm	*newShruberry(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm	*newPresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm	*newRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeForm(std::string type, std::string target) {
	int	i = 0;

	while (_cases[i] && type != _cases[i])
		i++;
	if (functions[i])
		return (functions[i](target));
	throw InvalidForm();
}

const char* Intern::InvalidForm::what() const throw() {
	return ("Invalid Format");
}

