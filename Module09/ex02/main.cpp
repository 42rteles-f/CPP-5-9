#include "PmergeMe.hpp"

int	main(void)
{
	int	array[12] = {123123, 98, 100, 3, 5, 2, 1, 21, 31, 44, 999, 1123};
	std::list<int>	myList(array, array + 12);

	PmergeMe::listFordJohnson(myList);
	for (std::list<int>::iterator it = myList.begin();
			it != myList.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}