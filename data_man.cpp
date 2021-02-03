#include <iostream>
using namespace std;

int age_1;
int age_2;
int age_3;

int& getAgeP(int = 1);

int main () {
	for(int i = 1; i <= 3; i++) {
		cout << "Enter age_" << i << " : ";
		cin >> getAgeP(i);
	}

	cout << "Age 1 = " << age_1 << endl;
	cout << "Age 2 = " << age_2 << endl;
	cout << "Age 3 = " << age_3 << endl;
}

int& getAgeP(int i) {
	switch(i) {
		case 2:
			return age_2;
		case 3:
			return age_3;
		default :
			return age_1;
	}
}
