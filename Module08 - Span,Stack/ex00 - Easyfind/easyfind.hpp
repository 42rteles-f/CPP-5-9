/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:38 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/11 16:18:38 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

/*
	Returns a iterator to the element or stack.end() if it doesnt find.
*/
template <typename T>
typename T::iterator easyfind(T& stack, int find) {
	return (std::find(stack.begin(), stack.end(), find));
}

#endif