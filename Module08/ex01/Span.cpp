/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:24 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/11 16:18:24 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():
_max(INT_MIN), _min(INT_MAX), _limit(0), _added(0), _short(INT_MAX)
{}

Span::Span(unsigned int N):
_max(INT_MIN), _min(INT_MAX), _limit(N), _added(0), _short(INT_MAX)
{}

Span::Span(Span& tocopy):
_limit(tocopy._limit)
{
	*this = tocopy;
}

Span::~Span() {}

Span&	Span::operator=(const Span& tocopy) {
	_max = tocopy._max;
	_min = tocopy._min;
	_short = tocopy._short;
	_long = tocopy._long;
	_added = tocopy._added;
	_numbers = tocopy._numbers;
	return (*this);
}

void	Span::updateShort(const int number) {
	int	difference = 0;

	for (size_t i = 0; i < _numbers.size(); i++) {
		difference = std::abs(_numbers[i] - number);
		if (difference < _short)
			_short = difference;
	}
}

void	Span::updateLong(const int number) {
	if (number > _max)
		_max = number;
	if (number < _min)
		_min = number;
	_long = _max - _min;
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	while (start != end) {
		try { addNumber(*start); } catch (...) { throw; }
		start++;
	}
}

void	Span::addNumber(const int number) {
	if (_added == _limit)
		throw std::runtime_error("Span is Full.");
	_added++;
	updateShort(number); 
	updateLong(number);
	_numbers.push_back(number);
}


int		Span::shortestSpan(void) {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers for a Span.");
	return (_short);
}

int		Span::longestSpan(void) {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers for a Span.");
	return (_long);
}