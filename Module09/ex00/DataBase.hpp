/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:20:17 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/13 23:05:47 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <map>
# include <string>
# include <fstream>

class DataBase {
	private:
		const	std::string		PATH;
		const	char			SEPARATOR;
		std::deque<std::string>	date;
		std::deque<std::string>	value;
		std::map<std::string, std::string>	data;

		DataBase();
		DataBase(const DataBase& copy);

		void	loadFile(std::string file);

	public:
		DataBase(std::string file, char separator);
		~DataBase();

		DataBase&   operator=(const DataBase& copy);

		std::string	getValue(std::string date) const;
}

#endif