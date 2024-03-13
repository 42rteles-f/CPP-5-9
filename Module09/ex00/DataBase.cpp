/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:30:35 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/13 23:08:18 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"

DataBase::DataBase():
PATH("data.csv"), SEPARATOR(',')
{
	loadFile();
}

DataBase::DataBase(const DataBase& copy):
PATH(copy.PATH), SEPARATOR(copy.SEPARATOR)
{
	*this = copy;
}

DataBase::DataBase(std::string file, char separator):
PATH(file), SEPARATOR(separator)
{
	loadFile();
}


DataBase::~DataBase() {}

DataBase&	DataBase::operator=(const DataBase& copy) {
	this->date = copy.date;
	this->rate = copy.rate;
}

void    DataBase::loadFile(void) {
	std::ifstream   file;
	std::string		line;
	size_t			pos;

	file.open(PATH);
	if (!file.is_open())
		throw std::runtime_error("Failed to Open " + PATH);

	while (std::getline(file, line) && validateLine(line))
	{
		pos = line.find(SEPARATOR);
		if (pos == line.npos || line.find(SEPARATOR, pos + 1) != line.npos)
			throw std::runtime_error(PATH + " Incorrect Format.");			
		data.insert(line.substr(0, pos), line.substr(pos + 1));
		// date.push_back(line.substr(0, pos));
		// value.push_back(line.substr(pos + 1));
	}
}

std::string	DataBase::getValue(std::string date) {
	while (get)
}
