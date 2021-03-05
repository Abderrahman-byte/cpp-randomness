#include <iostream>
#include <climits>


int main () {
	int current, min = INT_MAX ;

	for(int i = 0; i < 10; i++) {
		std::cout << "Entrez entier de case " << i << " : " ;
		std::cin >> current ;
		min = current < min ? current : min ;
	}

	std::cout << "MIN : " << min << std::endl;

	return 0;
}
