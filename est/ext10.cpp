#include <iostream>

int main () {
	int N;

	do {
		std::cout << "Entrez un entier entre 0 et 20 : ";
		std::cin >> N;

		if(N < 0 || N > 20) std::cout << "[ERREUR] l'entier doit etre entre 0 et 20." << std::endl;
	} while(N < 0 || N > 20);

	std::cout << "N+17 = " << N + 17 << std::endl;

	return 0;
}
