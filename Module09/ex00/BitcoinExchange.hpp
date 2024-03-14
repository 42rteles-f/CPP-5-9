/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:20:17 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/14 22:28:52 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <map>
# include <string>
# include <fstream>
# include <sstream> 

typedef struct s_bitdate {
	int	year;
	int	month;
	int	day;
} t_bitdate;

class BitcoinExchange {
	private:
		const	std::string		PATH;
		const	char			SEPARATOR;
		std::map<std::string, std::string>	data;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);

		void	loadFile();
		bool	validValue(std::string line);
		bool	leapYear(int year);
		bool	validDay(t_bitdate date);
		bool	validDate(std::string line);

	public:
		BitcoinExchange(std::string file, char separator);
		~BitcoinExchange();

		BitcoinExchange&   operator=(const BitcoinExchange& copy);
		BitcoinExchange&   operator>>(const BitcoinExchange& copy);

		std::string	getValue(std::string date) const;
} ;

#endif