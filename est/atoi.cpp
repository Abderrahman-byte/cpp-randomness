#include <iostream>
#include <cstring>
#include <cstdlib>

int main () {
	char text[10];

	std::cout << "Entrez un text : " ;
	std::cin >> text;
	
	std::cout << atoi(text) << std::endl;
	return 0;
}

