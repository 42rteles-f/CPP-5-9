#pragma once

# include <list>
# include <vector>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>


typedef void	(*t_exe)(...);

class PmergeMe {
	private:
		static std::list<int>	_list;
		static std::vector<int>	_vector;
		void	PmergeMe::makePairs();
		void	PmergeMe::binaryInsert();
		void	PmergeMe::sortFordJohnson(std::list<int>& list, t_exe , t_exe insert);

	public:
		PmergeMe();
		PmergeMe(PmergeMe& copy);
		~PmergeMe();

		PmergeMe&	operator=(PmergeMe& copy);
} ;

