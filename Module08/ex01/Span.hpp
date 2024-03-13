/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:21 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/11 16:18:21 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <list>
# include <algorithm>
# include <climits>

class Span {
	private:
		int					_max;
		int					_min;
		int					_short;
		int					_long;
		std::vector<int>	_numbers;

		Span();

		void	updateShort(const int number);
		void	updateLong(const int number);

	public:
		Span(const Span& tocopy);
		Span(const unsigned int N);
		~Span();

		Span&	operator=(const Span& tocopy);

		void	addNumber(const int number);
		void	addNumber(std::vector<int>::iterator start,
							std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);
} ;

#endif