#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>

unsigned int randomize();

int main() {
	for(int i = 0; i < 100; i++) {
		std::cout << "[*] random() = " << randomize() << std::endl;
	}

	return 0;
}

unsigned int randomize() {
	static unsigned int x_n =  rand();
	static unsigned int m = rand() % INT_MAX;

	const int a = rand() % 100 >> rand() % 2;
	const int b = rand() % 100 << rand() % 2;

	unsigned int x_n1 = (a * x_n + b) % m;
	x_n = x_n1;

	return x_n;
}
