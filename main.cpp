//#include "PMergeMe.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


std::vector<int> JacobsthalSequencing(size_t size){
	std::vector<int> jacob;
	if (size== 0)
		return jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	if (size > 1)
	{
		while(1){
			int next = jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2];
			jacob.push_back(next);
			if (next>size)
				break;
		}
	}
	return jacob;
}


int main(int argc, char **argv)
{
	std::vector<int> oui = JacobsthalSequencing(10);

	for (size_t i = 0; i < oui.size(); i++) {
		std::cout << oui[i] << std::endl;
	}

	return 0;
}


