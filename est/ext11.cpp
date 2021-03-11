#include <iostream>

int main () {
	int n = 0, quit = false;

	do {
		int cmd;

		std::cout << "n = " << n << std::endl;
	
		std::cout << "[1] Ajouter 1" << std::endl;
		std::cout << "[2] Multiplier 2" << std::endl;
		std::cout << "[3] Soustraire 4" << std::endl;
		std::cout << "[4] Quitter" << std::endl;
		
		std::cout << "Entrez une operation >>> ";
		std::cin >> cmd;

		switch(cmd) {
			case 1:
				n += 1;
				break;

			case 2:
				n *= 2;
				break;

			case 3:
				n -= 4;
				break;

			case 4:
				quit = true;
				break;	

			default :
				std::cout << "\033[0;31m[ERREUR] Numero d'operation n'exist pas\033[0m" << std::endl;	
		}

		std::cout << std::endl;
	} while(!quit);

	
	std::cout << "n = " << n << std::endl;
	return 0;
}
