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

void	printVector(std::vector<int> vector) {
	for (std::vector<int>::iterator it = vector.begin();
				it != vector.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

void	PmergeMe::sortFordJohnson(std::vector<int>& numbers) {
	std::vector<int>::iterator	eraser;
	std::vector<int>			larger;
	int							move, counter, total;

	if (numbers.size() < 2)
		return ;
	counter = 0;
	total = numbers.size() / 2;
	while(counter < total) {
		move = (numbers[counter] < numbers[counter + 1] ? numbers[counter] : numbers[counter + 1]);
		larger.insert(larger.end(), move);
		eraser = numbers.begin();
		std::advance(eraser, counter + (move == numbers[counter + 1]));
		numbers.erase(eraser);
		counter++;
		// printVector(numbers);
		// printVector(larger);
	}
	sortFordJohnson(numbers);
	binaryJacobsthalInsert(numbers, larger);
}

// 1 2 3 4 5 6 7 8 9 0 
// 1 3 4 5 6 7 8 9 0
// 1 3 5 6 7 8 9 0
     