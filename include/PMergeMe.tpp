

template<typename container>
std::vector<std::pair <int,int> > pairmaker(container T, std::vector<std::pair<int,int> > pairs){
	typename container::iterator it = T.begin();
	while(it != T.end())
	{
		int first = *it++;
		if(it ==T.end())
		{
			pairs.push_back(std::make_pair(first, -1));
			break;
		}
		int second = *it++;
		if(first>second)
		{
			pairs.push_back(std::make_pair(first, second));
		}
		else{
			pairs.push_back(std::make_pair(second,first));
		}
	}
	return pairs;
}


// tentative de création de petite fonction ici pour la creation de la mainchain big

// template<typename container>
// void sortingmainchain(std::vector<std::pair<int,int> >pairs, container &big, container &smalls){
	
// 	size_t sizeofpair = pairs.size();

// 	for(size_t i = 0; i < sizeofpair ; ++i){
// 		big.push_back(pairs[i].first);
// 		if(pairs[i].second != -1)
// 			smalls.push_back(pairs[i].second);
// 	}
// 	big = FJSort(big);
// }



template<typename container>
container FJSort(container T){
	
	if (T.size() <= 1)
		return T;
	// typename container::iterator it = T.begin();
	std::vector<std::pair<int, int> > pairs;
	container big;
	container smalls;

	pairs.reserve(T.size() / 2 + 1);
	pairs = pairmaker(T, pairs);
	// while(it != T.end())
	// {
	// 	int first = *it++;
	// 	if(it ==T.end())
	// 	{
	// 		pairs.push_back(std::make_pair(first, -1));
	// 		break;
	// 	}
	// 	int second = *it++;
	// 	if(first>second)
	// 	{
	// 		pairs.push_back(std::make_pair(first, second));
	// 	}
	// 	else{
	// 		pairs.push_back(std::make_pair(second,first));
	// 	}
	// }

	for(size_t i = 0; i < pairs.size(); ++i){
		big.push_back(pairs[i].first);
		if(pairs[i].second != -1)
			smalls.push_back(pairs[i].second);
	}
	big = FJSort(big);
	// sortingmainchain(pairs, big, smalls);

	std::vector<int> jacob = JacobsthalSequencing(smalls.size());

	size_t prev = 0;
	size_t smallsize = smalls.size();
	size_t jacobsize = jacob.size();

	for(size_t i = 0; i < jacobsize; i++)
	{
		size_t indice = std::min(static_cast<size_t>(jacob[i]), smallsize);
		for(size_t j = indice; j>prev; j--){
			int x = smalls[j-1];
			typename container::iterator pos = std::lower_bound(big.begin(),big.end(), x); 
			big.insert(pos, x);
		}
		prev = indice;
	}
	for (size_t i = smalls.size(); i > prev; --i)
	{
		int x = smalls[i-1];
		typename container::iterator pos = std::lower_bound(big.begin(), big.end(), x);
		big.insert(pos, x);
	}
	return big;
}