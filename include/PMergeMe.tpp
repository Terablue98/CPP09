

template<typename container>
container FJSort(container T){
	
	if (T.size() <= 1)
		return T;
	typename container::iterator it = T.begin();
	std::vector<std::pair<int, int> > pairs;
	container big;
	container smalls;
	std::cout << "container size: " << T.size() << std::endl;
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

	for(size_t i = 0; i < pairs.size(); ++i){
		big.push_back(pairs[i].first);
		if(pairs[i].second != -1)
			smalls.push_back(pairs[i].second);
	}
	big = FJSort(big);
	
	std::vector<int> jacob = JacobsthalSequencing(smalls.size());
	

	size_t prev = 0;
	for(size_t i = 0; i < jacob.size(); i++)
	{

		size_t indice = std::min(static_cast<size_t>(jacob[i]), smalls.size());
		for(size_t j = indice; j>prev; j--){
			int x = smalls[i-1];
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