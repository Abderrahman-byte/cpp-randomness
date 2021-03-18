#include <iostream>

#define TAILLE 10

int search(int [], int, int);
void supprimer(int [], int, int);

int main () {
	int numbers[TAILLE]; 
	int v, v_index;

	for(int i = 0; i < TAILLE; i++) {
		std::cout << "Entrez entier numbers[" << i << "] : " ;
		std::cin >> numbers[i];
	}

	std::cout << "\nEntrez entier a rechercher : ";
	std::cin >> v;

	v_index = search(numbers, TAILLE, v);

	if(v_index >= 0) supprimer(numbers, TAILLE, v_index);
	
	std::cout << std::endl;

	for(int i = 0; i < TAILLE; i++)
		std::cout << numbers[i] << '\t';
	
	std::cout << std::endl;

	return 0;
}

int search(int array[], int cout, int v) {
	int index = -1;

	for(int i = 0; i < cout; i++) {
		if(array[i] == v) {
			index = i;
			break;
		}
	}

	return index;
}

void supprimer(int array[], int cout, int index) {
	for(int i = index; i < cout; i++) {
		if(i < cout - 1) array[i] = array[i + 1] ;
		else array[i] = 0;
	}
}
