
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T& stack, int find) {
	return std::find(stack.begin(), stack.end(), find);
}

#endif