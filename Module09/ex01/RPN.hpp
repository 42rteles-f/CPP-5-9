#pragma once

# include <stack>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream> 

# define ERROR 10

class RPN {
	private:
		static std::stack<int>	expression;

		static bool	isOperation(std::string input);
		static void	solveOperation(int operation);
		static int		takeTop(void);
		RPN();
		RPN(std::string);
		RPN(RPN& copy);
		~RPN();
		RPN&	operator=(RPN& copy);

	public:
		static bool	calculate(std::string expression);
} ;

