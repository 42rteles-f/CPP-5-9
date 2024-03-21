#pragma once

# include <list>
# include <vector>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>

typedef std::vector<int>::iterator	(*t_exe)(std::vector<int>::iterator, std::vector<int>::iterator, int);

class PmergeMe {
	private:
		static const int	jacobsthal[50];
		std::list<int>		_numbers;

		void	PmergeMe::binaryInsert(std::vector<int>, std::vector<int>, t_exe);
		// void	PmergeMe::binaryInsert(std::list<int>, std::list<int>, t_exe);
		void	PmergeMe::sortFordJohnson(std::list<int>& list, t_exe transfer, t_exe insert);

	public:
		PmergeMe();
		PmergeMe(PmergeMe& copy);
		~PmergeMe();

		PmergeMe&	operator=(PmergeMe& copy);
} ;

