
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <list>
# include <algorithm>
# include <climits>

class Span {
	private:
		int					_max;
		int					_min;
		int					_short;
		int					_long;
		const int			_limit;
		int					_added;
		std::vector<int>	_numbers;

		Span();
		Span(Span& tocopy);

		void	updateShort(const int number);
		void	updateLong(const int number);

	public:
		Span(unsigned int N);
		~Span();

		Span&	operator=(Span& tocopy);

		void	addNumber(const int number);
		int		shortestSpan(void);
		int		longestSpan(void);
} ;

Span::Span():
_max(INT_MIN), _min(INT_MAX), _limit(0), _added(0), _short(INT_MAX)
{}

Span::Span(unsigned int N):
_max(INT_MIN), _min(INT_MAX), _limit(N), _added(0), _short(INT_MAX)
{}


Span::~Span() {}

void	Span::updateShort(const int number) {
	int	difference = 0;

	for (int i = 0; i < _numbers.size(); i++) {
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


#endif