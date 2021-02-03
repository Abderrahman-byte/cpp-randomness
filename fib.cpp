#include <iostream>
using namespace std;

#define SIZE 93

long long int fib(int) ;

int main() {
	int n;

	cout << "Enter seq : " ;
	cin >> n;
	cout << '\n';

	for(int i = 0; i < n; i++) {
		cout << "fab(" << i << ") = " << fib(i) << endl;
	}

	return 0;
}

long long int fib(int n) {
	static long long int store[SIZE];
	
	if(n >= SIZE) return -1;

	if(store[n] != 0) return store[n];
	else if(n == 0 || n == 1) return n;
	else { long long int fn = fib(n - 1) + fib(n - 2); store[n] = fn; return fn; }
}
