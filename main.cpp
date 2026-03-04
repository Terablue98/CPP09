#include "PMergeMe.hpp"


// std::vector<int> JacobsthalSequencing(size_t size){
// 	std::vector<int> jacob;
// 	if (size== 0)
// 		return jacob;
// 	jacob.push_back(0);
// 	jacob.push_back(1);
// 	if (size > 1)
// 	{
// 		while(1){
// 			int next = jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2];
// 			jacob.push_back(next);
// 			if (next>size)
// 				break;
// 		}
// 	}
// 	return jacob;
// }


bool is_positive_num(std::string str)
{
	if (str.empty()){
		return false;
	}
	for (size_t i = 0; i<str.length(); i++)
	{
		if((!isdigit(str[i])))
			return false;
	}
	return true;
}
template<typename container>
void printcontainer(const container& ex)
{
	typename container::const_iterator it = ex.begin();
	typename container::const_iterator end = ex.end();

	while(it != end)
	{
		std::cout << *it;
		++it;
		if(it != end)
			std::cout<<" ";
		
	}
	std::cout<<std::endl;
}
void parseInput(int argc, char **argv, std::vector<int> &vec, std::deque<int> &deq){
	for (int i = 1; i<argc; i++)
	{
		std::string arg = argv[i];

		if (!is_positive_num(arg)){
			std::cout<< "numbers are not positive numbers"<<std::endl;
			return ;
		}
		long num = std::strtol(arg.c_str(), NULL,10);
		if(num > INT_MAX){
			std::cout<< "overflow"<<std::endl;
			return ;
		}
		if (is_duplicated(vec, static_cast<int>(num))){
			std::cout << "duplicated inside the container" << std::endl;
			return ;
		}
		vec.push_back(static_cast<int>(num));
		deq.push_back(static_cast<int>(num));
	}
}


bool is_duplicated(const std::vector<int> &vec, int value){
	for(size_t i = 0; i<vec.size(); i++){
		if (vec[i] == value)
			return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	if (argc > 3000 || argc< 2){
		std::cout<<"there is a wrong number of args" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;
	try{
		parseInput(argc, argv, vec, deq);
		std::cout << "Before: ";
		printcontainer(vec);
		
		clock_t startVec=clock();
		FJSort(vec);
		clock_t endVec=clock();
		std::cout << "after for vec: ";
		printcontainer(vec);

		clock_t startDeq=clock();
		FJSort(deq);
		clock_t endDeq=clock();
		std::cout << "after for deq: ";
		printcontainer(deq);

		double vecTime = (double)(endVec - startVec)
						 / CLOCKS_PER_SEC * 1000000;

		double deqTime = (double)(endDeq - startDeq)
						 / CLOCKS_PER_SEC * 1000000;

		std::cout << "Time to process a range of "
				  << vec.size()
				  << " elements with std::vector : "
				  << vecTime << " us" << std::endl;

		std::cout << "Time to process a range of "
				  << deq.size()
				  << " elements with std::deque  : "
				  << deqTime << " us" << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << "error: " <<e.what()<< std::endl;
		return 1;
	}
	

	return 0;
}


