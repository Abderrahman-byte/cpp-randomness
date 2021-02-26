#include <iostream>

int main () {
	int sum, tmp;	

	std::cout << "Entrez la entier 1 : " ;
	std::cin >> tmp;
	sum += tmp;

	std::cout << "Entrez la entier 2 : " ;
	std::cin >> tmp;
	sum += tmp;

	std::cout << "Entrez la entier 3 : " ;
	std::cin >> tmp;
	sum += tmp;

	std::cout << "Entrez la entier 4 : " ;
	std::cin >> tmp;
	sum += tmp;
	
	std::cout << "Entrez la entier 5 : " ;
	std::cin >> tmp;
	sum += tmp;

	std::cout << "La moyenne : " << (float)sum / 5.0 << std::endl;


	return 0;
}
