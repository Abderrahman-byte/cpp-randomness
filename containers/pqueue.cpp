#include <iostream>
#include <queue>

#define MAX_FIB 45

typedef unsigned long long long_t;

using namespace std;

long_t fib(unsigned int);

int main() {
	priority_queue<int> pq;

	for(int i = 1; i < 100; i++) {
		pq.push(i * -1);
	}

	while(!pq.empty()) {
		int n = pq.top();
		n *= -1;
		cout << "f(" << n << ") = " <<  fib(n) << endl;
		pq.pop();
	}
}

long_t fib(unsigned int n) {
	static long_t images[MAX_FIB];

	if(n > MAX_FIB) return 0;
	else if(n == 0 || n == 1) return n;
	else if(images[n] != 0) return images[n];
	else {
		int fib_n = fib(n - 1) + fib(n - 2);
		images[n] = fib_n;
		return fib_n;
	}
}
