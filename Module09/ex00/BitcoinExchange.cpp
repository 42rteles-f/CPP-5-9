/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:30:35 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/25 18:11:29 by rteles-f         ###   ########.fr       */
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

bool	BitcoinExchange::leapYear(int year) const {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool	BitcoinExchange::validDay(t_bitdate date) const {
	int	limit;

	if (date.month == 2)
		limit = 28 + leapYear(date.year);
	else
		limit = 30 + ((date.month > 7) ? ((date.month - 7) % 2) : (date.month % 2));
	if ((date.day < 0 || date.day > limit))
		return (false);
	return (true);
}

bool	BitcoinExchange::validDate(std::string line) const {
	t_bitdate	date;
	char		end;

	if (std::sscanf(line.c_str(), "%d-%d-%d%c",
			&date.year, &date.month, &date.day, &end) != 3
			|| date.year < 0 || date.month < 0 || date.month > 12
			|| !validDay(date))
		throw std::runtime_error(std::string("Error: bad input => ") + line);
	return (true);
}

bool	BitcoinExchange::validValue(std::string line) const {

    std::istringstream iss(line);
    double	value = 0;
	char	end;

	if (std::sscanf(line.c_str(), "%lf%c", &value, &end) != 1)
		throw std::runtime_error("Error: Impossibble Conversion.");
    if (value < 0.0)
		throw std::runtime_error("Error: not a positive number.");
	if (value > 1000.0)
		throw std::runtime_error("Error: too large number.");
    return (true);
}

std::pair<std::string, std::string>	BitcoinExchange::lineToPair(std::ifstream& file, int separator) {

	std::string			line;
	size_t				pos;

	if (!std::getline(file, line))
		return (std::make_pair("", ""));
	while ((pos = line.find(' ')) != line.npos)
		line.erase(pos, 1);
	pos = line.find(separator);
	if (pos != line.npos)
		return (std::make_pair(line.substr(0, pos), line.substr(pos + 1)));
	else
		return (std::make_pair(line.substr(0, pos), std::string("")));
		
}

void    BitcoinExchange::loadFile(void) {
	std::ifstream   file;
	std::pair<std::string, std::string>	it;

	file.open(this->path.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	while (file.is_open()) {
		it = lineToPair(file, separator);
		if (it.first.length())
			data.insert(it);
		else
			file.close();
	}
}

void    BitcoinExchange::initDataBase(std::string file, char separtor) {
	this->path = file;
	this->separator = separtor;
	try { loadFile(); } catch (...) { throw; };
}

std::string    BitcoinExchange::getValue(std::string target) const {
	
	std::map<std::string, std::string>::const_iterator	find;

	find = data.lower_bound(target);
	if ((*find).first == target || find == data.begin())
		return ((*find).second);
	--find;
	return ((*find).second);
}

void    BitcoinExchange::worthByDate(std::string path, int separator) {

	std::pair<std::string, std::string>	log;
	std::ifstream	file;
	std::string		rate;
	double			value;

	file.open(path.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::getline(file, rate);
	log = lineToPair(file, separator);
	while (file.good()) {
		try {
			if (validDate(log.first) && validValue(log.second))
				rate = getValue(log.first);
			value = std::atof(log.second.c_str()) * std::atof(rate.c_str());
			std::cout << log.first << " => " << log.second << " = "
				<< value << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		log = lineToPair(file, separator);
	}
}
