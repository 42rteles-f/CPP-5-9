/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/13 18:06:55 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <fstream>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
		bool				_signed;

	public:
		AForm();
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		AForm(const AForm& tocopy);
		virtual ~AForm();

		AForm& operator=(const AForm& tocopy);

		std::string 	getName() const;
		int 			getGradeToSign() const;
		int 			getGradeExec() const;
		bool 			isSigned() const;
		void 			beSigned(const Bureaucrat& obj);
		int				isValidGrade(int grade) const;
		virtual void	execute(Bureaucrat const & executor) = 0;

		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		} ;
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		} ;
		class FormNotSigned: public std::exception {
			public:
				const char* what() const throw();
		} ;
} ;

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif