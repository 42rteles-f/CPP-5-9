#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN& copy) {
	*this = copy;
}

RPN::~RPN() {}

void	RPN::loadExpression(std::string expression) {
	std::istringstream	iss(expression);
	char				piece;

	while (iss >> piece)
		this->expression.push(piece);
}

bool	RPN::isOperation(int input) {
	return ((input == '+' || input == '-' || input == '*' || input == '/'));
}

void	RPN::calculate(std::string input) {

	int	size;
	int	result = 0;
	int	operation;

	loadExpression(input);
	size = expression.size();
	for (int i = 0; i < size; i++) {
		operation = expression.top();
		if (!isOperation(operation))
			throw std::runtime_error("Error: Invalid RPN.");
	}
}










