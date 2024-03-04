/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:12:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/21 19:25:34 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("Presidential", 25, 5), _target("None")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("Presidential", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& tocopy)
{
	*this = tocopy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{ std::cout << " < Presidential Destructor called. >" << std::endl; }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& tocopy) {
	if (this == &tocopy)
		return (*this);
	this->_target = tocopy._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw FormNotSigned();
	else if (executor.getGrade() >  this->getGradeExec())
		throw GradeTooLowException();

	std::cout << _target << " has been Pardoned by Zaphod Beeblebrox" << std::endl;
}
