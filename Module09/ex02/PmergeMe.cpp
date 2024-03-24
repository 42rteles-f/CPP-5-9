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
void	setFunctions(T test) {

}

void	PmergeMe::sortFordJohnson(std::list<int>& numbers, t_exe transfer, t_exe insert) {
	std::list<int>::iterator	first = numbers.begin();
	std::list<int>::iterator	second = numbers.begin();
	std::list<int>::iterator	move;
	std::list<int>				larger;

	if (numbers.size() < 2)
		return ;
	second++;
	while(first != numbers.end() && second != numbers.end()) {
		move = (*first < *second ? first : second);
		std::advance(first, 2);
		std::advance(second, 2);
		transfer(larger.end(), numbers, move);
	}
	sortFordJohnson(larger, transfer, insert);
	binaryInsert(numbers, larger, insert);
}

