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
path(""), separator(0)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}
 
BitcoinExchange::BitcoinExchange(std::string file, char separator):
path(file), separator(separator)
{
	try { loadFile(); } catch (...) { throw; };
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy) {
	this->path = copy.path;
	this->separator = copy.separator;
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
		limit = 30 + ((date.month > 7) ? ((date.month - 7) % 2) : (date.month % 2));
	if ((date.day > 0 && date.day <= limit))
		return (true);
	return (false);
}

bool	BitcoinExchange::validDate(std::string line) {
	t_bitdate	date;
	char		end;

	if (std::sscanf(line.c_str(), "%d-%d-%d%c",
			&date.year, &date.month, &date.day, &end) != 4
			|| date.year < 0 || date.month < 0 || date.month > 12
			|| !validDay(date))
		throw std::runtime_error(std::string("Error: bad input => ") + line);
	return (true);
}

bool	BitcoinExchange::validValue(std::string line) {

    std::istringstream iss(line);
    double value = 0;

	if (!(iss >> value))
		throw std::runtime_error("Error: impossibble convergion.");
    if (value < 0.0)
		throw std::runtime_error("Error: not a positive number.");
	if (separator == AMOUNT &&  value > 1000.0)
		throw std::runtime_error("Error: too large number.");
    return (true);
}

void    BitcoinExchange::loadFile(void) {
	std::ifstream   file;
	std::string		line;
	size_t			pos;

	file.open(this->path.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	while (std::getline(file, line))
	{
		pos = line.find(this->separator);
		if (pos == line.npos || line.find(this->separator, pos + 1) != line.npos)
			throw std::runtime_error(std::string("Error: ") + path + " incorrect format.");
		if (!data.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1))).second)
			throw std::runtime_error(std::string("Error: ") + path + " repeating date.");
	}
}

void    BitcoinExchange::initDataBase(std::string file, char separtor) {
	this->path = file;
	this->separator = separtor;
	loadFile();
}

std::string    BitcoinExchange::getValue(std::string date) const {
	std::map<std::string, std::string>::const_iterator	closer;

	closer = data.begin();
	while (closer != data.end() && (*closer).first != date) {
		closer++;
	}
	if (closer == data.end()) {
		closer--;
		closer--;
	}
	return ((*closer).second);
}

// void    BitcoinExchange::worthByDate(std::string file) {

// 	std::map<std::string, std::string>::iterator	it;
// 	std::string	rate;
// 	std::pair<std::string, std::string>	line;
// 	std::string	line;
// 	double		value;

// 	while (std::getline(line)) {
// 		try {
// 			(validDate((*it).first)) && (validValue((*it).second));
// 			rate.clear();
// 			rate = date.getValue((*it).first);
// 			value = std::atof((*it).second.c_str()) * std::atof(rate.c_str());
// 			std::cout	<< (*it).first << " => "
// 						<< (*it).second << " = "
// 						<< value
// 						<< std::endl;
// 		}
// 		catch (std::exception& e) {
// 			std::cout << e.what() << std::endl;
// 		}
// 		it++;
// 	}
// }

void    BitcoinExchange::worthByDate(BitcoinExchange& date) {

	std::map<std::string, std::string>::iterator	it;
	std::string	rate;
	double		value;

	it = data.begin();
	while (it != data.end()) {
		try {
			(validDate((*it).first)) && (validValue((*it).second));
			rate.clear();
			rate = date.getValue((*it).first);
			value = std::atof((*it).second.c_str()) * std::atof(rate.c_str());
			std::cout	<< (*it).first << "=>"
						<< (*it).second << " = "
						<< value
						<< std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		it++;
	}
}

		// data.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1)));
		// std::cout	<< "key: " << (*it).first
		// 			<< " value: " << (*it).second << std::endl;

// std::string	BitcoinExchange::getValue(std::string date) {
// 	while (get)
// }
