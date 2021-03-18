#include <iostream>

int max(int [], int);

int main () {
	int numbers[10];
	int max_index;

	for(int i = 0; i < 10; i++) {
		std::cout << "Entrer entier du case " << i << " : ";
		std::cin >> numbers[i];
	}

	max_index = max(numbers, 10);

	std::cout << "Max : Numbers[" << max_index << "] = " << numbers[max_index] << std::endl;

	return 0;
}

int max(int arr[], int count) {
	int max_index = 0;

	for(int i = 1; i < count; i++) {
		if(arr[max_index] < arr[i]) max_index = i;
	}

	return max_index;
}
