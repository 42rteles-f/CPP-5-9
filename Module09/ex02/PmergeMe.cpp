#include "PmergeMe.hpp"

std::stack<int> PmergeMe::expression;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe& copy) {
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(PmergeMe& copy) {
	(void)copy; return (*this);
}

template<typename T>
void	findPosition(T container, T compare) {
	int	count = 0;

	while (*container) {
		if (*compare > *container)
			count++;
		container++
	}
	return (count);
}

template<typename T>
void	swapVector(T begin, T change, int pos) {
	T hold;

	*hold = *change;
	*change = begin[pos];
	begin[pos] = *hold;
}

template<typename T>
void	swapList(T begin, T change, int pos) {
	T	hold;
	int	find = 0;

	while (*begin && find != pos)
		begin++;
	if (find == pos) {
		*hold = *begin;
		*begin = *change;
		*change = *hold;
	}
}

template<typename T>
void	PmergeMe::insertionSort(T begin, T end, t_exe swap) {
	int	pos;
	T	it = begin;

	while (it != end) {
		pos = findPosition(begin, it);
		swap(begin, it, pos);
		it++;
	}
}

void	PmergeMe::makePairs() {
	std::list<int>::iterator first = _list.begin();
	std::list<int>::iterator second = _list.begin();
	std::list<int>					smaller;
	std::list<int>					bigger;

	second++;
	while(*first && *second) {
		if (*first < *second) {
			smaller.push_back(*first);
			bigger.push_back(*second);
		}
		else {
			smaller.push_back(*second);
			bigger.push_back(*first);
		}
		first++;
		second++;
	}
	if (*first)
		bigger.push_back(*first);
	insertionSort(bigger.begin(), smaller.end());
}