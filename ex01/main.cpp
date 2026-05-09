#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>

int main(int argc, char **argv)
{
	
	if (argc != 2)
	{
		std::cout << "Error : Usage : exec + arg"<< std::endl;	
		return 1;
	}
	RPN abc;
	abc.calculate(argv[1]);
	return 0;
}


