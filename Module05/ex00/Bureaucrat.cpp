/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:13 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/05 17:47:00 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
{ std::cout << "Bureaucrat Default Constructor called." << std::endl; }

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
	return (*this);
}

void	Bureaucrat::setGrade(int grade) {
	if (grade < 1) {
		// Bureaucrat::GradeTooLowException;
		return ;
	}
	else if (grade > 150) {
		//Bureaucrat::GradeTooHighException;
		return ;
	}
	this->_grade = grade;
}

int	Bureaucrat::getGrade(void) {
	return (this->_grade);
}

void	Bureaucrat::setName(int grade) {
	if (grade < 1) {
		// Bureaucrat::GradeTooLowException;
		return ;
	}
	else if (grade > 150) {
		//Bureaucrat::GradeTooHighException;
		return ;
	}
	this->_grade = grade;
}

std::string	Bureaucrat::getName(void) {
	return (this->_name);
}