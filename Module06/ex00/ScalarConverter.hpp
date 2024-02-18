/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/15 17:25:53 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <exception>
# include <climits>
# include <iomanip>
# include <cmath>
# include <cfloat>

enum {
	CHAR, INT, DOUBLE, FLOAT, OVERFLOW,IMPOSSIBLE
} ;

class ScalarConverter {
	private:
		// bool	_overflow[4];
		ScalarConverter();
		ScalarConverter(const ScalarConverter& tocopy);
		~ScalarConverter();

	public:
		static void	convert(const std::string convert);

		ScalarConverter& operator=(const ScalarConverter& tocopy);
} ;

#endif