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

void	PmergeMe::insertionSort(std::list<int>& numbers, t_exe asd, t_exe swap) {
	std::list<int>::iterator	first = numbers.begin();
	std::list<int>::iterator	second = numbers.begin();
	std::list<int>::iterator	move;
	std::list<int>				smaller;

	if (numbers.size() < 2)
		return ;
	second++;
	while(first != numbers.end() && second != numbers.end()) {
		move = (*first < *second ? first : second);
		std::advance(first, 2);
		std::advance(second, 2);
		smaller.splice(smaller.end(), numbers, move);
	}
	insertionSort(smaller);
	insertionSort(numbers);
	binaryInsert(numbers, smaller);
}

