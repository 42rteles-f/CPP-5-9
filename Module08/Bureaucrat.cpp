/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:13 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/05 10:39:34 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
{ std::cout << "Bureaucrat Default Constructor called." << std::endl; }

Bureaucrat::Bureaucrat(std::string name, int grade):
{
	std::cout << "Bureaucrat Default Constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& tocopy)
{
	std::cout << "Bureaucrat Copy Constructor called." << std::endl;
	*this = tocopy;
}

Bureaucrat::~Bureaucrat()
{ std::cout << "Bureaucrat Destructor called." << std::endl; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& tocopy) {
	if (this == &tocopy)
		return (*this);
	// this->_grade = tocopy._grade;
	return (*this);
}

// std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
// 	os	<< "Bureaucrat " << obj.getName()
// 		<< " has Grade: " << obj.getGrade() << std::endl;
// 	return (os);
// }
