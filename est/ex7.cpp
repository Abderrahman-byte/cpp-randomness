#include <iostream>

int main () {
	int n;

	std::cout << "Entrer un entier : ";
	std::cin >> n;

	std::cout << (n >= 50 && n <= 70 ? "GAGNE" :  "PERDU") << std::endl;

	return 0;
}
