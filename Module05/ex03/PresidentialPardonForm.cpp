/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:12:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/14 13:15:20 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("Shrubbery", 25, 5), _target("None")
{
	std::cout << " < Shrubbery Default Constructor called. >" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("Shrubbery", 25, 5), _target(target)
{
	std::cout << " < Shrubbery Default Constructor called. >" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& tocopy)
{
	std::cout << " < Shrubbery Copy Constructor called. >" << std::endl;
	*this = tocopy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{ std::cout << " < Shrubbery Destructor called. >" << std::endl; }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& tocopy) {
	if (this == &tocopy)
		return (*this);
	this->_target = tocopy._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (!this->isSigned())
		throw FormNotSigned();
	else if (executor.getGrade() >  this->getGradeExec())
		throw GradeTooLowException();

	std::cout << _target << " has been Pardoned by Zaphod Beeblebrox" << std::endl;
}
