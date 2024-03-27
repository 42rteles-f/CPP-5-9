/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/05 11:17:22 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {
	private:
		AForm		*(*functions[4])(std::string);
		char		*_cases[4];
	public:
		Intern();
		Intern(const Intern& tocopy);
		~Intern();

		Intern& operator=(const Intern& tocopy);

		AForm	*makeForm(std::string type, std::string targer);

		class InvalidForm: public std::exception {
			public:
				const char* what() const throw();
		} ;
} ;

#endif