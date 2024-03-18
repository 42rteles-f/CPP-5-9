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

/*
	The loop will transfer the splitted input in to the token variable.
	First it will try to pass all numbers it encounters into the stack.
	Once it finds something that is not a valid number, it must be a operator.
	If the string exists and the operation failed, theres something wrong with either
the operation or the input.
	if there is no string, meaning its the end of the input, and the expression has more than one number left,
that means the input is wrong.
*/
bool	RPN::calculate(std::string input) {
	std::istringstream	iss(input);
	std::string			token = "start";

	while (!iss.eof())
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