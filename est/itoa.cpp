#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

int main () {
	int n; char buffer[33];

	std::cout << "Entrez un entier : " ;
	std::cin >> n;
	
	std::cout << itoa(n, buffer, 10) << std::endl;
	std::cout << itoa(n, buffer, 10) << std::endl;
	std::cout << itoa(n, buffer, 10) << std::endl;
	std::cout << itoa(n, buffer, 10) << std::endl;

	return 0;
}

