#include "PmergeMe.hpp"

const int PmergeMe::jacobsthal[100] = {
	-1,0,1,3,5,7,10,13,16,19,22,26,30,34,38,42,46,50,54,
	58,62,66,71,76,81,86,91,96,101,106,111,116,121,
	126,131,136,141,146,151,156,161,166,171,177,183,
	189,195,201,207,213,219,225,231,237,243,249,255};

PmergeMe::PmergeMe()
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

// void	PmergeMe::binaryInsert(std::list<int> base, std::list<int> merge) {

// 	merge.sort();
// 	base.merge(merge);
// }

// void	PmergeMe::binaryInsert(std::vector<int> base, std::vector<int> merge, t_exe findPos) {

// 	int	index = 0;
// 	int	current;
// 	std::vector<int>::iterator	pos;

// 	while (jacobsthal[index] < merge.size()) {
// 		current = (jacobsthal[index] < merge.size() ? jacobsthal[index] : merge.size() - 1);
// 		while (current > jacobsthal[index - 1]) {
// 			pos = std::lower_bound(base.begin(), base.end(), merge[current]);
// 			base.insert(pos, merge[current]);
// 			current--;
// 		}
// 	}
// }

std::list<int>::iterator	PmergeMe::listIndex(std::list<int>& base, int index) {
	std::list<int>::iterator	it = base.begin();
	int	find;

	find = 0;
	while (it != base.end() && find != index) {
		it++;
		find++;
	}
	return (it);
}

std::list<int>::iterator	PmergeMe::findNext(std::list<int>& base, int find) {
	std::list<int>::iterator	it = base.begin();

	while (it != base.end() && find > *it) {
		it++;
	}
	return (it);
}

void	PmergeMe::jacobsthalInsert(std::list<int>& base, std::list<int>& merge) {

	int	index;
	int	current;
	std::list<int>::iterator	take;
	std::list<int>::iterator	put;

	index = 0;
	do {
		index++;
		current = (jacobsthal[index] < (int)merge.size() ? jacobsthal[index] : merge.size() - 1);
		while (current > jacobsthal[index - 1]) {
			take = listIndex(merge, current);
			put = findNext(base, *take);
			base.insert(put, *take);
			current--;
		}
	} while (jacobsthal[index] < (int)merge.size());
}

void	PmergeMe::listFordJohnson(std::list<int>& numbers) {
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
	listFordJohnson(numbers);
	jacobsthalInsert(numbers, smaller);
}


// void	PmergeMe::sortFordJohnson(std::vector<int>& numbers) {
// 	std::vector<int>::iterator	first = numbers.begin();
// 	std::vector<int>::iterator	second = numbers.begin();
// 	std::vector<int>::iterator	move;
// 	std::vector<int>			larger;

// 	if (numbers.size() < 2)
// 		return ;
// 	second++;
// 	while(first != numbers.end() && second != numbers.end()) {
// 		move = (*first < *second ? first : second);
// 		std::advance(first, 2);
// 		std::advance(second, 2);
// 		larger.insert(larger.end(), *move);
// 		numbers.erase(move);
// 	}
// 	sortFordJohnson(larger);
// 	binaryInsert(numbers, larger);
// }