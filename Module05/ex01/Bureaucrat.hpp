/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/24 16:52:13 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string, int);
		Bureaucrat(const Bureaucrat& tocopy);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& tocopy);

		int			getGrade(void) const;
		void		setGrade(int grade);
		std::string	getName(void) const;
		void		increaseGrade(void);
		void		decreaseGrade(void);
		void		signForm(Form& form) const;

		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		} ;
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		} ;
} ;

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif