/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/24 16:53:42 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
		bool				_signed;

	public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form& tocopy);
		~Form();

		Form& operator=(const Form& tocopy);

		std::string 	getName() const;
		int 			getGradeToSign() const;
		int 			getGradeExec() const;
		bool 			isSigned() const;
		void 			beSigned(const Bureaucrat& obj);
		int				isValidGrade(int grade) const;

		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		} ;
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		} ;
} ;

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif