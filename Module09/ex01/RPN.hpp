#pragma once

# include <stack>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream> 

class RPN {
	private:
		std::stack<int>	expression;

		void	loadExpression(std::string expression);
		bool	isOperation(int input);
		int		RPN::getOperation(void);
		int		RPN::takeTop(void);
		int		RPN::checkTop(void);


	public:
		RPN();
		RPN(RPN& copy);
		~RPN();

		RPN&	operator=(RPN& copy);

		void	calculate(std::string expression);
} ;

