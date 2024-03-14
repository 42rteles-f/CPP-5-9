/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:30:35 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/14 23:19:46 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange():
PATH("data.csv"), SEPARATOR(',')
{
	try { loadFile(); } catch (...) { throw; };
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy):
PATH(copy.PATH), SEPARATOR(copy.SEPARATOR)
{
	*this = copy;
}

BitcoinExchange::BitcoinExchange(std::string file, char separator):
PATH(file), SEPARATOR(separator)
{
	try { loadFile(); } catch (...) { throw; };
}


BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy) {
	this->data = copy.data;
	return (*this);
}

bool	BitcoinExchange::leapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool	BitcoinExchange::validDay(t_bitdate date) {
	int	limit;

	if (date.month == 2)
		limit = 28 + leapYear(date.year);
	else
		limit = 30 + (date.month > 7) ? ((date.month - 7) % 2) : (date.month % 2);
	if ((date.day > 0 && date.day <= limit))
		return (true);
	return (false);
}

bool	BitcoinExchange::validDate(std::string line) {
	t_bitdate	date;

	if (std::sscanf(line.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day) != 3)
		return (false);
	if (date.year < 0 || date.month < 0 || date.month > 12 || !validDay(date))
		return (false);
	return (true);
}

bool	BitcoinExchange::validValue(std::string line) {

    std::istringstream iss(line);
    double value = 0;
    
    if (!(iss >> value) || value < 0.0 || value > 1000.0)
        return (false);
    return (true);
}

void    BitcoinExchange::loadFile(void) {
	std::ifstream   file;
	std::string		line;
	size_t			pos;

	file.open(PATH.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	while (std::getline(file, line))
	{
		pos = line.find(SEPARATOR);
		if (pos == line.npos || line.find(SEPARATOR, pos + 1) != line.npos)
			throw std::runtime_error(PATH + " Incorrect Format.");
		if (!data.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1))).second)
			throw std::runtime_error(PATH + " Repeating Date.");
	}
}
	// std::map<std::string, std::string>::iterator it = data.begin();
	// while (it != data.end()) {
	// 	if (!validDate((*it).first))
	// 		std::cout << "invalid date " << (*it).first << std::endl;
	// 	// if (!validValue((*it).second))
	// 	// 	std::cout << "invalid value " << (*it).second << std::endl;
	// 	it++;
	// }
		// data.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1)));
		// std::cout	<< "key: " << (*it).first
		// 			<< " value: " << (*it).second << std::endl;

// std::string	BitcoinExchange::getValue(std::string date) {
// 	while (get)
// }
