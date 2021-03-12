#include <iostream>

#define TAILLE 10

int main () {
	int numbers[TAILLE]; int v;

	for(int i = 0; i < TAILLE; i++) {
		std::cout << "Entrez entier numbers[" << i << "] : " ;
		std::cin >> numbers[i];
	}

	std::cout << "\nEntrez entier a rechercher : ";
	std::cin >> v;

	for(int i = 0; i < TAILLE; i++) {
		if(numbers[i] == v) {
			std::cout << v << " se trouve dans le tableau" << std::endl;
			break;
		} else if(i == TAILLE - 1) std::cout << v << " ne se trouve pas dans le tableau" << std::endl;
	}
	return 0;
}
