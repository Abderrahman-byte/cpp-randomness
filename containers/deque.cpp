#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

int main() {
	deque<int> data;
	bool back = true;

	data.push_back(0);

	while(true) {
		string input;
		int x = 0;

		cout << "Enter a number >>> " ;
		cin >> input ;

		if(input.compare("q") == 0 || input.compare("quit") == 0 || input.compare("exit") == 0) break;
		
		stringstream num(input);
		num >> x;
		
		if(back) {
			data.push_back(x);
		} else {	
			data.push_front(x);
		}

		back = !back;
	}
	
	cout << endl;
	while(!data.empty()) {
		int value = data[0];
		cout << value << endl;
		data.pop_front();
		data.push_back(value);
	}
	cout << endl;

	return 0;
}
