/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:52:42 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/13 22:14:14 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"

int main(int ac, char **av)
{
	DataBase	csv("data.csv", ',');
	DataBase	input(av[1], '|');
}