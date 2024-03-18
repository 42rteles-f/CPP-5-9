#pragma once

# include <list>
# include <vector>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream> 

typedef void	(*t_exe)();

class PmergeMe {
	private:
		static std::list<int>	_list;
		static std::vector<int>	_vector;
		void	PmergeMe::makePairs();
		template<typename T>
		void	PmergeMe::insertionSort(T begin, T end, t_exe);

	public:
		PmergeMe();
		PmergeMe(PmergeMe& copy);
		~PmergeMe();

		PmergeMe&	operator=(PmergeMe& copy);
} ;

