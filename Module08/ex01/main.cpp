#include "Span.hpp"
#include <stack>



int	main(void)
{
	Span test(50);

	for (int i = -30; i < -15; i+=2)
		test.addNumber(i);
	std::cout << "short: " << test.shortestSpan() << std::endl;
	std::cout << "long: " << test.longestSpan() << std::endl;
	test.addNumber(100);
	std::cout << "short: " << test.shortestSpan() << std::endl;
	std::cout << "long: " << test.longestSpan() << std::endl;
	test.addNumber(101);
	std::cout << "short: " << test.shortestSpan() << std::endl;
	std::cout << "long: " << test.longestSpan() << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::stack<int>	asd;
}