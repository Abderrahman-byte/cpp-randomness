#include <iostream>

void repeat(int, std::string);

int main () {
	int n;

	std::cout << "Entrez le nombre de ligne : ";
	std::cin >> n;
	
	for(int i = n; i >= 0; i--) {
		repeat(n - i, " ");
		repeat(i * 2 + 1, "*");
		std::cout << std::endl;
	}
	return 0;
}

void repeat(int n, std::string toRepeat) {
	for(int i = 0; i < n; i++)
		std::cout << toRepeat;
}
