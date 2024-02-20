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

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():
_name("Default AForm"), _grade_to_sign(150), _grade_to_exec(150), _signed(false)
{}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute):
_name(name), _grade_to_sign(isValidGrade(grade_to_sign)), _grade_to_exec(isValidGrade(grade_to_execute)), _signed(false)
{}

AForm::AForm(const AForm& tocopy):
_name(""), _grade_to_sign(150), _grade_to_exec(150), _signed(false)
{
	std::cout << " < AForm Copy Constructor called. >" << std::endl;
	*this = tocopy;
}

AForm::~AForm()
{}

AForm& AForm::operator=(const AForm& tocopy) {
	if (this == &tocopy)
		return (*this);
	this->_signed = tocopy._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os	<< "Name " << obj.getName()
		<< ". Grade to Sign: " << obj.getGradeToSign()
		<< ". Grade to Execute: " << obj.getGradeExec()
		<< ". Signed = " << (obj.isSigned() ? "true" : "false");
	return (os);
}

std::string AForm::getName() const {
	return (_name);
}

int AForm::getGradeToSign() const {
	return (_grade_to_sign);
}

int AForm::getGradeExec() const {
	return (_grade_to_exec);
}

bool AForm::isSigned() const {
	return (_signed);
}

void AForm::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() <= _grade_to_sign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

int	AForm::isValidGrade(int grade) const {
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

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade Too Low.");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade Too Hight.");
}

const char* AForm::FormNotSigned::what() const throw() {
	return ("Form not Signed.");
}
