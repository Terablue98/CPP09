#include <PmergeMe.hpp>



std::vector<std::pair<int, int>> sortPairs(std::vector<std::pair<int, int>> &paired){
	for (size_t i = 1; i< paired.size(); i++)
	{
		std::pair<int, int> index = paired[i];
		int j = i-1;
		while(j>= 0 && paired[j].first > index.first )
		{
			paired[j+1] = paired[j];
			j--;
		}
		paired[j+1]= index;
	}
	return paired;
}


template<typename container>
std::vector<std::pair<int, int>> PairandSort(container& T){
	
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i+1 < T.size(); i+=2)
	{
		if (T[i] > T[i+1])
			pairs.push_back(std::make_pair(T[i], T[i+1]));
		else
			pairs.push_back(std::make_pair(T[i+1], T[i]));
	}
	sortPairs(pairs);
	return pairs;
}




template<typename container>
container &BuildMainChain(std::vector<std::pair<int,int>> paired, container &MainChain){
	for (size_t i = 0; i < paired.size();i++)
		MainChain.push_back(paired[i].first);
	MainChain.push_back(paired[0].second);
	return MainChain;
}



template<typename container>
container& fordjohnsonSort(container&T)
{
	std::vector<std::pair<int,int>> paired;
	paired = PairandSort(T);
	container mainChain;
	BuildMainChain(paired, mainChain);

	std::vector<int> jacob;
	jacob = JacobsthalSequencing(paired.size());
	binaryinsertion(mainChain, paired,jacob);

	T = mainChain;
	return T;
}







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

//1 - create the jacobsthal sequencing

//2 - pair the number from the container

//3 - sort the higher number and add the lower number of the lower higher number pair

//4 - use the sequencing jacobsthal to introduce the lower number

//5 - use bitshifting with the sequencing?