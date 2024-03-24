/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:28:02 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/24 21:51:36 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main(int ac, char **av) {

    if (ac != 2)
        return (0);

    int array[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(array, array + 5);

    std::vector<int>::iterator it = easyfind(vec, std::atoi(av[1]));

    if (it != vec.end()) {
        std::cout << "Found at position: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}