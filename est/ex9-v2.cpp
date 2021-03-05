#include <iostream>
#include <climits>

int max(int [], int);

int main () {
	int numbers[10] ;

	for(int i = 0; i < 10; i++) {
		std::cout << "Entrez entier de case " << i << " : " ;
		std::cin >> numbers[i] ;
	}

	std::cout << "MAX : " << max(numbers, 10) << std::endl;

	return 0;
}

int max(int numbers[], int size) {
	int max = INT_MIN;

	for(int i = 0; i < size; i++)
		if(numbers[i] > max) max = numbers[i];

	return max;
}
