#include "PmergeMe.hpp"

const int PmergeMe::jacobsthal[35] = {
	-1, 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
	21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
	1431655765
};

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe& copy) {
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(PmergeMe& copy) {
	(void)copy; return (*this);
}

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

std::list<int>::iterator	PmergeMe::listElement(std::list<int>& base, int find) {
	std::list<int>::iterator	it = base.begin();

	while (it != base.end() && find > *it) {
		it++;
	}
	return (it);
}

void	PmergeMe::jacobsthalInsert(std::list<int>& base, std::list<int>& merge) {

	int	index, current;
	std::list<int>::iterator	where, what;

	index = 0;
	do {
		index++;
		current = (jacobsthal[index] < (int)merge.size() ? jacobsthal[index] : merge.size() - 1);
		while (current > jacobsthal[index - 1]) {
			what = listIndex(merge, current);
			where = listElement(base, *what);
			base.insert(where, *what);
			current--;
		}
	} while (jacobsthal[index] < (int)merge.size());
}

void	PmergeMe::sortFordJohnson(std::list<int>& numbers) {

	std::list<int>::iterator	first, second, move;
	std::list<int>				smaller;

	if (numbers.size() < 2)
		return ;
	first = second = numbers.begin();
	second++;
	while(first != numbers.end() && second != numbers.end()) {
		move = (*first < *second ? first : second);
		std::advance(first, 2);
		std::advance(second, 2);
		smaller.splice(smaller.end(), numbers, move);
	}
	sortFordJohnson(numbers);
	jacobsthalInsert(numbers, smaller);
}

void	PmergeMe::binaryJacobsthalInsert(std::vector<int>& base, std::vector<int>& merge) {

	std::vector<int>::iterator	where;
	int	index, current;

	index = 0;
	do {
		index++;
		current = (jacobsthal[index] < (int)merge.size() ? jacobsthal[index] : merge.size() - 1);
		while (current > jacobsthal[index - 1]) {
			where = std::lower_bound(base.begin(), base.end(), merge[current]);
			base.insert(where, merge[current]);
			current--;
		}
	} while (jacobsthal[index] < (int)merge.size());
}

void	PmergeMe::sortFordJohnson(std::vector<int>& numbers) {
	std::vector<int>	copy, smaller;
	int	size = numbers.size() - 1;
	int	i = 0;

	if (numbers.size() < 2)
		return ;
	copy = numbers;
	numbers.clear();
	while (i < size)
	{
		if (copy[i] > copy[i + 1]) {
			numbers.push_back(copy[i]);
			smaller.push_back(copy[i + 1]);
		}
		else {
			numbers.push_back(copy[i + 1]);
			smaller.push_back(copy[i]);
		}
		i += 2;
	}
	if (copy.size() % 2)
		numbers.push_back(copy[i]);
	sortFordJohnson(numbers);
	binaryJacobsthalInsert(numbers, smaller);
}



