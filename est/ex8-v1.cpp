#include <iostream>

int main () {
	int n = 10;

	std::cout << "En utilisant for loop :" << std::endl;
	for(int i = 10; i <= 20; i++) std::cout << i << '\t';
	std::cout << std::endl;

	std::cout << "En utilisant while :" << std::endl;
	while(n <= 20) std::cout << n++ << '\t';
	std::cout << std::endl; 

	return 0;
}
