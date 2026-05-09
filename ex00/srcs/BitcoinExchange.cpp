#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange() : BitcoinExchange("data.csv"){
	LoadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(std::string const &filename){
	LoadDatabase(filename);
}

void BitcoinExchange::LoadDatabase(std::string const &datafile){
	std::ifstream in(datafile.c_str());
	if (!in)
		throw WrongDataFileException();
	std::string line;
	while (std::getline(in,line))
	{
		size_t coma = line.find(',');
		if (coma == std::string::npos)
			continue;
		std::string date = line.substr(0,coma);
		std::string stringvalue = line.substr(coma+1);
		double value = std::atof(stringvalue.c_str());
		_database[date] = value;
	} 
}

BitcoinExchange::~BitcoinExchange(){
	
}
