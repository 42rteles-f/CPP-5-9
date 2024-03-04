/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:16 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/04 20:56:08 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array {
	private:
		T		*_array;
		size_t	_size;

		Array():
		_array(NULL), _size(0) {};

	public:
		Array(unsigned int n):
			_array(new T[n]()), _size(n) {};
		Array(const Array& tocopy) {
			*this = tocopy;
		};
		~Array() {
			delete[] _array;
			_size = 0;
		}

		Array&	operator=(const Array& tocopy)
		{
			if (this == &tocopy)
				return (*this);
			if (_array)
				delete[] _array;
			_array = new T[tocopy._size];
			_size = tocopy._size;
			for (size_t i = 0; i < _size; i++)
				_array[i] = tocopy._array[i];
			return (*this);
		};
		T&		operator[](size_t element)
		{
			if (element >= _size)
				throw std::exception();
			return (_array[element]);
		};

		size_t	size(void) const {
			return (_size);
		};
} ;

#endif