#include <iostream>

using namespace std;

int main () {
	int age;
	char name[20];

	cout << "Enter your name : ";
	cin >> name;
	cout << "Enter your age : ";
	cin >> age;

	cout << name << " is " << age << " years old" << endl;

	return 0;
}
