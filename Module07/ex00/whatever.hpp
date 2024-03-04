/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:45:31 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/04 19:05:08 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template<typename T>
void    swap(T& first, T& second) {
	T	hold;

	hold = first;
	first = second;
	second = hold;
}

template<typename T>
T       min(T& first, T& second) {
	return ((first < second) ? first : second);
}

template<typename T>
T       max(T& first, T& second) {
	return ((first > second) ? first : second);
}

#endif