#include <iostream>

int main () {
	double largeur, longueur;

	std::cout << "Entrez largeur : ";
	std::cin >> largeur;

	std::cout << "Entrez longueur : ";
	std::cin >> longueur;
	
	std::cout << "Suface : " << largeur * longueur << std::endl;
	std::cout << "Perimetre : " << (largeur + longueur ) * 2 << std::endl;

	return 0;
}
