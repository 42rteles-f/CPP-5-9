#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN& copy) {
	*this = copy;
}

RPN::~RPN() {}

void	RPN::loadExpression(std::string input) {
	std::istringstream	iss(input);
	std::string			piece;

	while (iss >> piece && piece.length() == 1
			&& (std::isdigit(piece[0]) || isOperation(piece[0])))
			expression.push(piece[0]);
	if (!iss.eof())
		throw std::runtime_error("Error");
}

bool	RPN::isOperation(int input) {
	return ((input == '+' || input == '-' || input == '*' || input == '/'));
}

int		RPN::takeTop(void) {
	int	value;

	if (expression.empty())
		throw std::runtime_error("Error");
	value = expression.top();
	expression.pop();
	return (value);
}

int		RPN::getOperation(void) {

	int	operation;

	if (expression.empty() || !isOperation(expression.top()))
		throw std::runtime_error("Error");

	operation = takeTop();
	if ((operation == '+' || operation == '-'))
	{
		operation = 1;
		while (expression.size() && expression.top() == '+' || expression.top() == '-')
			operation *= ((takeTop() == '+') ? 1 : -1);
	}
	return (operation);
}

void	RPN::calculate(std::string input) {

	int	result = 0;
	int	operation;
	int	numbers[2];

	try {
		loadExpression(input);
		while (expression.size())
		{
			operation = getOperation();
			numbers[0] = takeTop() - '0';
			if (expression.size() && std::isdigit(expression.top()))
				numbers[1] = takeTop() - '0';
			else {
				numbers[1] = numbers[0];
				numbers[0] = result;
				result = 0;
			}
			if (operation == '*')
				result += numbers[0] * numbers[1];
			else if (operation == '/')
				result += numbers[0] / numbers[1];
			else
				result += numbers[0] + (operation * numbers[1]);
		}
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << result << std::endl;
}









