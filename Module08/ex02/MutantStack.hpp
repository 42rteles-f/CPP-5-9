/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:10 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/11 20:03:28 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template<typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		// typedef typename std::stack<T>::container_type::iterator const_iterator;
		MutantStack() {};
		MutantStack(MutantStack const &tocopy) {
			*this = tocopy;
		};
		~MutantStack() {};

		MutantStack&	operator=(MutantStack const& tocopy) {
			if (this != &tocopy)
				std::stack<T>::operator=(tocopy);
			return (*this);
		};

		iterator		begin(void) {
			return (this->c.begin());
		}
		iterator		end(void) {
			return (this->c.end());
		}
		// const_iterator	cbegin(void) {
		// 	return (this->c.begin());
		// }
		// const_iterator	cend(void) {
		// 	return (this->c.end());
		// }
} ;

#endif