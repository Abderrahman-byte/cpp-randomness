#include <iostream>

using namespace std;

int main() {
	int a,b,r;

	cout << "Enter a : ";
	cin >> a;
	cout << "Enter a : ";
	cin >> b;
	
	cout << a << " = " << b << " * " << ((double)a / (double)b) << endl ;
	cout << a << " = (" << b << " * " << (a / b) << ") + " << a % b << endl ;
	return 0;
}
