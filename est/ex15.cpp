#include <iostream>

int main () {
	int numbers[10], s = 0;

	for(int i = 0 ; i < 10; i++) {
		std::cout << "Entrez entier de la case " << i << " : ";
		std::cin >> numbers[i];

		if(numbers[i] >= 10) s++;
	}
	
	std::cout << "Nombre d'entier superieurs ou egal 10 : " << s << std::endl;
	return 0;
}
