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
#include "Bureaucrat.hpp"

Form::Form():
_name("Default Form"), _grade_to_sign(150), _grade_to_exec(150), _signed(false)
{ std::cout << "Form Default Constructor called." << std::endl; }

Form::Form(std::string name, int grade_to_sign, int grade_to_execute):
_name(name), _grade_to_sign(isValidGrade(grade_to_sign)), _grade_to_exec(isValidGrade(grade_to_execute)), _signed(false)
{ std::cout << "Form Define Constructor called." << std::endl; }

Form::Form(const Form& tocopy):
_name(""), _grade_to_sign(150), _grade_to_exec(150), _signed(false)
{
	std::cout << "Form Copy Constructor called." << std::endl;
	*this = tocopy;
}

Form::~Form()
{ std::cout << "Form Destructor called." << std::endl; }

Form& Form::operator=(const Form& tocopy) {
	if (this == &tocopy)
		return (*this);
	this->_signed = tocopy._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os	<< "Name " << obj.getName()
		<< ". Grade to Sign: " << obj.getGradeToSign()
		<< ". Grade to Execute: " << obj.getGradeExec()
		<< ". Signed = " << (obj.isSigned() ? "true" : "false");
	return (os);
}

std::string Form::getName() const {
	return (_name);
}

int Form::getGradeToSign() const {
	return (_grade_to_sign);
}

int Form::getGradeExec() const {
	return (_grade_to_exec);
}

bool Form::isSigned() const {
	return (_signed);
}

void Form::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() <= _grade_to_sign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

int	Form::isValidGrade(int grade) const {
	if (grade < 1) {
		throw GradeTooHighException();
		return (150);
	}
	else if (grade > 150) {
		throw GradeTooLowException();
		return (150);
	}
	return (grade);
}


const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade Too Low.");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade Too Hight.");
}
