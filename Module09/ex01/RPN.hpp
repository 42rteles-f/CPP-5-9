#pragma once

# include <stack>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream> 


class RPN {
	private:
		static std::stack<int>	expression;

		RPN();
		RPN(RPN& copy);
		~RPN();

		RPN&	operator=(RPN& copy);

		static bool	solveOperation(std::string operation);

	public:
		static bool	calculate(std::string expression);
} ;

