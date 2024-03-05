/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/05 11:36:34 by rteles-f         ###   ########.fr       */
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
		ScalarConverter();
		ScalarConverter(const ScalarConverter& tocopy);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& tocopy);

	public:
		static void	convert(const std::string convert);

} ;

#endif