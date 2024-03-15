/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:52:42 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/15 19:11:32 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	(void)av;
	BitcoinExchange	csv;
	BitcoinExchange	input;
	try {
		csv.initDataBase("data.csv", ',');
		csv.worthByDate(av[1], '|');
	}
	catch (std::exception& event) {
		std::cout << event.what() << std::endl;
	}
}