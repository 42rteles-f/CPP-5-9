/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/14 15:58:54 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& tocopy);
		~ScalarConverter();
		static void	printChar(std::string convert);
		static void	printInt(std::string convert);
		static void	printFloat(std::string convert);
		static void	printDouble(std::string convert);

	public:
		static void	convert(const std::string convert);

		ScalarConverter& operator=(const ScalarConverter& tocopy);
} ;

#endif