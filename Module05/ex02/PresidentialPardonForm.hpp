/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:10:58 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/20 21:36:39 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		std::string					_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& tocopy);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& tocopy);

		virtual void	execute(Bureaucrat const & executor);
} ;

#endif