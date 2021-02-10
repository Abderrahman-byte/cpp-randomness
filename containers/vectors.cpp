#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	vector<int> numbers;

	while(true) {
		string data;
		int x = 0;

		cout << "Enter a number >>> " ;
		cin >> data ;

		if(data.compare("q") == 0 || data.compare("quit") == 0 || data.compare("exit") == 0) break;
		
		stringstream num(data);
		num >> x;

		numbers.push_back(x);
	}

	cout << endl;
	
	// numbers.resize(numbers.size() - 1);
	
	if(!numbers.empty()) {
		for(int i = 0; i < numbers.size(); i++) {
			cout << numbers[i] << '\t' ;
		}
	}

	cout << endl;

	return 0;
}
