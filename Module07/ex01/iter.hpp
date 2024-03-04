/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:37:15 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/04 19:58:43 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstdio>
# include <iostream>

template<typename T>
void    iter(T *array, size_t length, void(*apply)(T&)){
    for (size_t i = 0; i < length; i++)
        apply(array[i]);
}

template<typename T>
void	templatePrint(T& variable) {
    std::cout << variable;
}

#endif