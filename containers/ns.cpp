#include <iostream>
#include <vector>
using namespace std;

namespace integers {
	int add(vector<int> numbers) {
		int some = 0;

		for (int i = 0; i < numbers.size(); i++) {
			some += numbers[i];
		}

		return some;
	}


	int multiply(vector<int> numbers) {
		int result = 1;

		for (int i = 0; i < numbers.size(); i++) {
			result *= numbers[i];
		}

		return result;
	}
}

namespace decimals {
	float add(vector<float> numbers) {
		float some = 0;

		for (float i = 0; i < numbers.size(); i++) {
			some += numbers[i];
		}

		return some;
	}


	float multiply(vector<float> numbers) {
		float result = 1;

		for (float i = 0; i < numbers.size(); i++) {
			result *= numbers[i];
		}

		return result;
	}
}


int main() {
	cout << decimals::add({9.9, 8.1, 1}) << endl;
	cout << decimals::multiply({9.9, 8, 1}) << endl;
	cout << integers::add({9, 8, 1}) << endl;
	cout << integers::multiply({9, 8, 1}) << endl;
	return 0;
}
