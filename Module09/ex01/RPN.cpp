#include "RPN.hpp"

std::stack<int> RPN::expression;

RPN::RPN() {}

RPN::RPN(RPN& copy) {
	*this = copy;
}

RPN::~RPN() {}

RPN&	RPN::operator=(RPN& copy) {
	(void)copy; return (*this);
}

bool	RPN::solveOperation(std::string operation)
{
	float	first, second;
	int		result;

	if (expression.size() < 2)
		return (false);
	first = expression.top();
	expression.pop();
	second = expression.top();
	expression.pop();
	if (operation == "*" || (operation == "/" && first))
		result = second * (operation == "*" ? first : (1.0 / first));
	else if (operation == "+" || operation == "-")
		result = second + (operation == "+" ? first : -first);
	else
		return (false);
	expression.push(result);
	return (true);
}

bool	RPN::calculate(std::string input) {
	std::istringstream	iss(input);
	std::string			token = "start";

	while (!token.empty())
	{
		token.clear();
		while (iss >> token && token.length() == 1 && std::isdigit(token[0]))
			expression.push(token[0] - '0');
		if ((!token.empty() && !solveOperation(token))
			|| (token.empty() && expression.size() != 1)) {
			std::cout << "Error" << std::endl;
			return (false);
		}
	}
	std::cout << expression.top() << std::endl;
	return (true);
}