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
void	PmergeMe::insertionSort(T begin, T end, t_exe swap) {
	int	pos;
	T	it = begin;

	while (it != end) {
		pos = findPosition(begin, it);
		swap(begin, it, pos);
		it++;
	}
}

void	PmergeMe::insertionSort(std::list<int> list) {
	std::list<int>::iterator	first = _list.begin();
	std::list<int>::iterator	second = _list.begin();
	std::list<int>				smaller;

	second++;
	while(*first && *second) {
		smaller.push_back(*first < *second ? *first : second);
		first++;
		second++;
	}
	if (list.size() > 2)
		insertionSort(smaller);
	binaryInsert(list, smaller);
}