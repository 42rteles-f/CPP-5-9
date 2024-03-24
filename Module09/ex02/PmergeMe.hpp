#pragma once

# include <list>
# include <vector>
# include <algorithm>

class PmergeMe {

	private:
		static const int	jacobsthal[100];

		PmergeMe();
		PmergeMe(PmergeMe& copy);
		~PmergeMe();

		PmergeMe&	operator=(PmergeMe& copy);

		static void	jacobsthalInsert(std::list<int>&, std::list<int>&);
		static void	binaryJacobsthalInsert(std::vector<int>&, std::vector<int>&);
		static std::list<int>::iterator	listIndex(std::list<int>& base, int index);
		static std::list<int>::iterator	listElement(std::list<int>& base, int index);

	public:
		static void	sortFordJohnson(std::list<int>& list);
		static void	sortFordJohnson(std::vector<int>& array);
} ;
