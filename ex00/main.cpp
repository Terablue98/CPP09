#include "BitcoinExchange.hpp"
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>

int main(int argc, char **argv)
{
	if (argc != 2)
		throw WrongArgException();
	std::map<std::string, double> input;
	std::map<std::string, double> data;


	// mettre ma data.csv inside a sorted container
	// checker la validite de mon input
	// pour celles qui marche trouver la bonne correspondance
	// pour celles qui ne marchent pas envoyer un code d'erreur
	//utiliser set ou map (map should be the best one) as a container list


		//parse toutes les lignes de l'input generer une par une
		//parse uniquement la ligne de l'input 1 par 1 pour ensuite trouver l'annee puis le mois puis le jour (ou le jour le plus proche dans la data base)
		// comment faire?
		//soit je cree une classe 
		//soit je ne cree pas de classe

		//pour chaque ligne s'assurer qu'il ait bien le bon format sinon throwing error mauvais format
		// re
	
	
}

// My plan is : Creating a class to retrieve the data.csv that my exercise gave me. this class will serve me as a reference later for the input user ill need to use 
// i ll  need to fill my map with all the data and rate exchange inside with getline , where 2 elements need to be retrieved the first one my string which will be the date where i will need to change it to number to compare it to other date(for that last part i don't know if i can just keep them as a string and still be correctly sorted)
// then i ll retrieve the second one : the exchange rate.
// Then when i have everything it ll be automatically sorted out ready to be use 
// the 2nd part of my exercise would be about parsing the 2nd input (the input user) to then thnks to my class be able to change the result correctly and send the correct dates with the correct result 





//je dois tester mes premieres fonctions si ma map se construit bien
