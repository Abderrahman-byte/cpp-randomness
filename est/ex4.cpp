#include <iostream>

int main () {
	float ht, quantite, tva;

	std::cout << "Entrer prix HT : ";
	std::cin >> ht;

	std::cout << "Entrer quantite (en kilo) : ";
	std::cin >> quantite;

	std::cout << "Entrer TVA : ";
	std::cin >> tva;

	std::cout << "TTC : " << HT * (1 + tva / 100) * quantite << std::endl; 
	return 0;
}
