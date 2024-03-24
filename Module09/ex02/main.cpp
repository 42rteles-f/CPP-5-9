#include "PmergeMe.hpp"

int	main(void)
{
	int	list_array[12] = {123123, 98, 100, 3, 5, 2, 98, 21, 31, 44, 999, 1123};
	int	vector_array[12] = {123123, 98, 100, 3, 5, 2, 98, 21, 31, 44, 999, 1123};
	std::list<int>	myList(list_array, list_array + 12);
	std::vector<int>	myVector(vector_array, vector_array + 12);

	PmergeMe::sortFordJohnson(myList);
	for (std::list<int>::iterator it = myList.begin();
			it != myList.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
	PmergeMe::sortFordJohnson(myVector);
	for (std::vector<int>::iterator it = myVector.begin();
			it != myVector.end(); it++) {
		std::cout << *it << ", ";
	}

}