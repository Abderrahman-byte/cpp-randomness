#include <iostream>

#define TAILLE 10

typedef enum { croissant, decroissant, constant, quelconque } tableau_type ;

tableau_type scanner(int [], int);

int main () {
	int numbers[TAILLE]; 
	std::string msg;
	
	for(int i = 0; i < TAILLE; i++) {
		std::cout << "Entrez entier numbers[" << i << "] : " ;
		std::cin >> numbers[i];
	}

	switch(scanner(numbers, TAILLE)) {
		case croissant :
			msg = "Le tableau est croissant";
			break;
			
		case decroissant :
			msg = "Le tableau est decroissant";
			break;

		case constant :
			msg = "Le tableau est constant";
			break;

		case quelconque :
			msg = "Le tableau est quelconque";
			break;
	}

	std::cout << msg << std::endl;
	
	return 0;
}

tableau_type scanner(int array[], int cout) {
	bool is_constant = true;
	bool is_asc = true;
	bool is_desc = true;

	for(int i = 0; i < cout - 1; i++) {
		if(is_constant && array[i] != array[i + 1]) is_constant = false;
		if(is_asc && array[i] > array[i + 1]) is_asc = false;
		if(is_desc && array[i] < array[i + 1]) is_desc = false;
	}

	if(is_constant) return constant;
	else if(is_asc) return croissant;
	else if(is_desc) return decroissant;
	else return quelconque;
}
