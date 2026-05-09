#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

class RPN{
	private :

	std::stack<int> _base;
	bool is_token(char c);

	public :
	RPN();
	~RPN();
	RPN(const RPN &smth);
	RPN &operator=(const RPN &smth);

	void calculate(std::string arg);
};


#endif