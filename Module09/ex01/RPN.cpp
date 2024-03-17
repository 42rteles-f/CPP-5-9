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

bool	RPN::solveOperation(int operation)
{
	float	first, second;
	int		result;

	first = expression.top();
	expression.pop();
	second = expression.top();
	expression.pop();
	if (operation == '*' || (operation == '/' && first))
		result = second * (operation == '*' ? first : (1.0 / first));
	else if (operation == '+' || operation == '-')
		result = second + (operation == '+' ? first : -first);
	else
		return (false);
	expression.push(result);
	return (true);
}

bool	RPN::calculate(std::string input) {
	std::istringstream	iss(input);
	std::string			piece;

	while (!iss.eof())
	{
		while (iss >> piece && piece.length() == 1 && std::isdigit(piece[0]))
			expression.push(piece[0] - '0');
		if (expression.size() < 2 || piece.length() != 1 || !solveOperation(piece[0])
			|| (iss.eof() && expression.size() != 1)) {
			std::cout << "Error" << std::endl;
			return (false);
		}
	}
	std::cout << expression.top() << std::endl;
	return (true);
}
