#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

// You have to create a program which outputs the value of a certain amount of bitcoin
// on a certain date.
// This program must use a database in csv format which will represent bitcoin price
// over time. This database is provided with this subject.
// The program will take as input a second database, storing the different prices/dates
// to evaluate.
// Your program must respect these rules:
// • The program name is btc.
// • Your program must take a file as an argument.
// • Each line in this file must use the following format: "date | value".
// • A valid date will always be in the following format: Year-Month-Day.
// • A valid value must be either a float or a positive integer, between 0 and 1000.
	class BitcoinExchange {
		private :
			std::map<std::string, double> _database;
			void LoadDatabase(std::string const &_Dataname);
		public :
		BitcoinExchange();
		BitcoinExchange(std::string const &filename);
		
		~BitcoinExchange();

	}



//file date | value


#endif