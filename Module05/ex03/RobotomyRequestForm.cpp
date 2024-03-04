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

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm():
AForm("Robotomy", 72, 45), _target("None")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("Robotomy", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& tocopy)
{
	*this = tocopy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{ std::cout << " < Robotomy Destructor called. >" << std::endl; }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& tocopy) {
	if (this == &tocopy)
		return (*this);
	this->_target = tocopy._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (!this->isSigned())
		throw FormNotSigned();
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();

	std::cout << "*DRILLING NOISES* ";
	std::srand(std::time(0));
	if ((std::rand() % 2))
		std::cout << _target << " has been Robotomized." << std::endl;
	else
		std::cout << "The Robotomy on " << _target << " has Failed." << std::endl;
}
