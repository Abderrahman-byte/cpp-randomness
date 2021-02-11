#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int n;
	bitset<8> byte;

	cout << "Enter a number : ";
	cin >> n;

	byte |= n;

	cout << n << " = " << byte.to_string() << endl; 

	return 0;
}
