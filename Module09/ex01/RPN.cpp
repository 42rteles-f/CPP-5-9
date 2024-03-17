#include "RPN.hpp"

std::stack<int> RPN::expression;

RPN::RPN() {}

RPN::RPN(RPN& copy) {
	*this = copy;
}

RPN::~RPN() {}

RPN&	RPN::operator=(RPN& copy) { (void)copy; return (*this); }

void	RPN::solveOperation(int operation)
{
	double	first, second;
	int		result;

	first = expression.top();
	expression.pop();
	second = expression.top();
	expression.pop();
	if (operation == '*' || operation == '/')
		result = second * (operation == '*' ? first : (1.0 / first));
	else
		result = second + (operation == '+' ? first : -first);
	expression.push(result);
}

bool	RPN::calculate(std::string input) {
	std::istringstream	iss(input);
	std::string			piece;

	while (!iss.eof())
	{
		while (iss >> piece && piece.length() == 1 && std::isdigit(piece[0]))
			expression.push(piece[0] - '0');
		if (expression.size() < 2 || !isOperation(piece)) {
			std::cout << "Error" << std::endl;
			return (false);
		}
		solveOperation(piece[0]);
	}
	std::cout << expression.top() << std::endl;
	return (true);
}

bool	RPN::isOperation(std::string input) {
	return (((input.length() == 1)
		&& (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')));
}
