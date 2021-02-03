#include <iostream>
using namespace std;

#define SIZE 64

typedef unsigned long long int large_t;

large_t factorial(int);
void init_data();

int main() {
	int n = 0;
	init_data();
	
	cout << "Enter a number : ";
	cin >> n;
	
	cout << "f(" << n << ") = " << factorial(n) << endl;
}

large_t factorial(int n) {
	static large_t cache[SIZE];

	if(n >= SIZE || n < 0) return 0;
	else if(cache[n] != 0) return cache[n];
	else if(n == 0 || n == 1) return 1;
	else {
		large_t fn = factorial(n - 1) * n;
		cache[n] = fn;
		return fn;
	}
}

void init_data() {
	for(int i = 0; i < SIZE; i++) factorial(i);
}
