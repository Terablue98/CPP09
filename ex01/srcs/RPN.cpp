#include <RPN.hpp>

RPN::RPN(){
}

RPN::~RPN(){
}

RPN &RPN::operator=(const RPN &smth){
	if(this != &smth){
		_base = smth._base;
	}
	return(*this);
}

RPN::RPN(const RPN &smth) : _base(smth._base){
}

void RPN::calculate(std::string arg){
	for (size_t i = 0; i <arg.length();i++){
		char c = arg[i];
		if (c == ' ')
			continue;
		if (isdigit(c))
		{
			int digit = c - '0';
			_base.push(digit);
			continue;
		}
		if (is_token(c)){
			if (_base.size() < 2){
				std::cout << "Error : an operator need 2 numbers to work";
				return ;
			}
			int second = _base.top();
			_base.pop();
			int first = _base.top();
			_base.pop();
			int result;
			switch (c) {
				case '+':
					result = first + second;
					break;
				case '-':
					result = first - second;
					break;
				case '*':
					result = first * second;
					break;
				case '/':
					if (second == 0){
						std::cout<< "error : cant divide a number by 0" << std::endl;
						return;
					}
					result = first / second;
					break;
			}
			_base.push(result);
		}
		else{
			std::cout<< "Error : only digits and operator are correct" << std::endl;
			return; 
		}
	}
	if(_base.size() != 1)
	{
		std::cout<< "Error : not enough operator" << std::endl;
		return;
	}
	std::cout << _base.top() << std::endl;
}

bool RPN::is_token(char c){
	if (c == '+' || c=='*' || c == '-' || c== '/')
		return true;
	return false;
}
