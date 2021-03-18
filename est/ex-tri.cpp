#include <iostream>

#define TAILLE 10

void trier_bulle(int [], int);
void swap(int&, int&);

int main () {
	int numbers[TAILLE]; 

	for(int i = 0; i < TAILLE; i++) {
		std::cout << "Entrez entier numbers[" << i << "] : " ;
		std::cin >> numbers[i];
	}
	
	/* AFFICHER TABLEAU AVANT LE TRIER */
	std::cout << "Tableau avant le trier :" << std::endl;
	for(int i = 0; i < TAILLE; i++) std::cout << numbers[i] << '\t';
	std::cout << std::endl;
	
	trier_bulle(numbers, TAILLE);

	/* AFFICHER TABLEAU APRES LE TRIER */
	std::cout << "Tableau apres le trier :" << std::endl;
	for(int i = 0; i < TAILLE; i++) std::cout << numbers[i] << '\t';
	std::cout << std::endl;
	
	return 0;
}

void trier_bulle(int array[], int cout) {
	bool done = false;

	while(!done) {
		done = true;

		for(int i = 0; i < cout - 1; i++) {
			if(array[i] > array[i + 1]) {
				done = false;
				swap(array[i], array[i + 1]);
			}
		}
	}
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
