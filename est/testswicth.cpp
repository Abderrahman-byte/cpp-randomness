#include <iostream>
#include <string>

int main () {
	std::string abbreviation;

	std::cout << ">>> " ;
	std::cin >> abbreviation ;

	switch(abbreviation) {
		case "M" :
			std::cout << "Monsieur" << std::endl;
			break;
	

		case "Mme" :
			std::cout << "Madame" << std::endl;
			break;

		case "Mlle" :
			std::cout << "Mademoiselle" << std::endl;
			break;


		default :
			std::cout << "Monsieur,Madame" << std::endl;
	}

	return 0;
}
