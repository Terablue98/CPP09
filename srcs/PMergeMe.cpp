#include <PMergeMe.hpp>



// std::vector<std::pair<int, int>> sortPairs(std::vector<std::pair<int, int>> &paired){
// 	for (size_t i = 1; i< paired.size(); i++)
// 	{
// 		std::pair<int, int> index = paired[i];
// 		int j = i-1;
// 		while(j>= 0 && paired[j].first > index.first )
// 		{
// 			paired[j+1] = paired[j];
// 			j--;
// 		}
// 		paired[j+1]= index;
// 	}
// 	return paired;
// }

// template<typename container>
// container<std::pair<int,int>> sortpairs(std::vector<std::pair<int,int>> &paired){

// }


// std::vector<std::pair<int, int>> sortPairs(std::vector<std::pair<int, int>> &paired){





//  Phase 3: Insert losers into sorted W using binary insertion in Ford-Johnson order
//     main = big  // Start with sorted winners as main run
//     insertion_order = jacobstahll(length(L))  // E.g., for 4: [2,1,0,3] (0-based indices for b3,b2,b1,b4)
//     for idx in insertion_order:
//         value = small(second)[idx]
//         pos = binary_search_position(main, value)  // Find insertion index
//         insert main at pos with value  // Shift and place

//     // Copy back to original array
//     for i = 0 to n-1:
//         A[i] = main[i]

// function binary_search_position(sorted_list, value):
//     low = 0
//     high = [length](/page/Length)(sorted_list)
//     while low < high:
//         mid = [floor](/page/Floor)((low + high) / 2)
//         if sorted_list[mid] < value:
//             low = mid + 1
//         else:
//             high = mid
//     return low  // Insertion point

// template<typename container>
// container &BuildMainChain(std::vector<std::pair<int,int>> paired, container &MainChain){
// 	for (size_t i = 0; i < paired.size();i++)
// 		MainChain.push_back(paired[i].first);
// 	MainChain.push_back(paired[0].second);
// 	return MainChain;
// }


std::vector<int> JacobsthalSequencing(size_t size){
	std::vector<int> jacob;
	if (size== 0)
		return jacob;
	// jacob.push_back(0);
	// jacob.push_back(1);
	if (size > 1)
	{
		while(1){
			size_t next = jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2];
			jacob.push_back(next);
			if (next>size)
				break;
		}
	}
	return jacob;
}


// template<typename container>
// container& fordjohnsonSort(container &T)
// {
// 	// std::vector<std::pair<int,int>> paired;
// 	paired = FJSort(T);
// 	container mainChain;
// 	BuildMainChain(paired, mainChain);

// 	std::vector<int> jacob;
// 	jacob = JacobsthalSequencing(paired.size());
// 	binaryinsertion(mainChain, paired,jacob);

// 	T = mainChain;
// 	return T;
// }


// template<typename container>
// container& fordjohnsonSort(container &T)
// {
// 	// std::vector<std::pair<int,int>> paired;

// 	container mainChain;
// 	container pending;
// 	typename

// 	BuildMainChain(paired, mainChain);

// 	std::vector<int> jacob;
// 	jacob = JacobsthalSequencing(paired.size());
// 	binaryinsertion(mainChain, paired,jacob);

// 	T = mainChain;
// 	return T;
// }







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

//1 - create the jacobsthal sequencing

//2 - pair the number from the container

//3 - sort the higher number and add the lower number of the lower higher number pair

//4 - use the sequencing jacobsthal to introduce the lower number

//5 - use bitshifting with the sequencing?