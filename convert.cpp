#include <iostream>
using namespace std;

int main() {
	const int len = 20;
	char name[len] ;

	cout << "Enter your name : ";
	cin >> name;
	
	for(int i = 0; i < len; i++) {
		if(name[i] == '\0') break;

		cout << (int)name[i] << ' ';
	}

	cout << endl;

	return 0;	
}
