#include "PmergeMe.hpp"
#include <ctime>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream> 
# include <iostream>
# include <algorithm>
# include <stack>
# include <map>
# include <string>
# include <fstream>
# include <sstream> 
# include <iomanip>

void	printVector(std::vector<int> vector) {

	int	limit = vector.size() - 1;

	for (int i = 0; i < limit; i++) {
		std::cout << vector[i] << " ";
	}
	std::cout << *(vector.end() - 1);
}

int	main(int ac, char **av)
{
	std::list<int>		myList;
	std::vector<int>	myVector;
	std::time_t			start, end;
	double				list_time, vector_time;
	int					number;
	char				last;

	if (ac < 2)
		return (1);
	for (size_t i = 1; av[i]; i++) {
		if (std::sscanf(av[i], "%i%c", &number, &last) != 1 || number < 0) {
			std::cout << "Invalid Input." << std::endl;
			return (2);
		}
		myList.push_back(number);
		myVector.push_back(number);
	}

	std::cout << std::fixed;

	std::cout << "Before:  "; printVector(myVector); std::cout << std::endl;

	start = std::clock();
	PmergeMe::sortFordJohnson(myVector);
	end = std::clock();
	vector_time = (double)(end - start) / CLOCKS_PER_SEC;

	start = std::clock();
	PmergeMe::sortFordJohnson(myList);
	end = std::clock();
	list_time = (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "After:   "; printVector(myVector); std::cout << std::endl;

	std::cout	<< "Time to process a range of " << myVector.size()
				<< " elements with std::vector " << vector_time << std::endl;
	std::cout	<< "Time to process a range of " << myList.size()
				<< " elements with std::list   " << list_time << std::endl;
}