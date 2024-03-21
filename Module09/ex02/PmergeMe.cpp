#include "PmergeMe.hpp"

const int PmergeMe<std>::jacobsthal[50] = {0, 1, 1, 9, 25, 121, 441, 1849, 7225, 29241, 116281, 466489,
1863225, 7458361, 29822521, 119311929, 477204025, 1908903481, 7635439161, 30542106169, 122167725625,
488672300601, 1954686406201, 7818751217209, 31274993684025};

PmergeMe::PmergeMe() :
{}

PmergeMe::PmergeMe(PmergeMe& copy) {
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(PmergeMe& copy) {
	(void)copy; return (*this);
}

std::vector<int>::iterator	reLowerBound(std::vector<int>::iterator a, std::vector<int>::iterator b, int c) {
	return (std::lower_bound(a, b, c));
}

void	PmergeMe::binaryInsert(std::vector<int> base, std::vector<int> merge, t_exe findPos) {

	int	index = 0;
	int	current;
	std::vector<int>::iterator	pos;

	while (jacobsthal[index] < merge.size()) {
		current = (jacobsthal[index] < merge.size() ? jacobsthal[index] : merge.size() - 1);
		while (current > jacobsthal[index - 1]) {
			pos = std::lower_bound(base.begin(), base.end(), merge[current]);
			base.insert(pos, merge[current]);
			current--;
		}
	}
}

void	PmergeMe::sortFordJohnson(std::list<int>& numbers, t_exe transfer, t_exe swap) {
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
	sortFordJohnson(smaller, transfer, swap);
	std::vector<int> a, b;
	binaryInsert(a, b, reLowerBound);
}

