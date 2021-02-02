#include <iostream>
using namespace std;

bool isPrime(int);
int getPrime(int);

int main() {
	int a ;

	cout << "Enter a : ";
	cin >> a;
	
	cout << "Prime : " << getPrime(a) << endl;
	return 0;
}

int getPrime(int n) {
	int found = 0, i = 0;
	
	while(found < n) {
		i++;
		if(isPrime(i)) found++;
	}

	return i;
}

bool isPrime(int n) {
	int i = 2;

	while(i < n) {
		if(n % i == 0) {
			return false;
		}
		i++;
	}

	return true;
}
