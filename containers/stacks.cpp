#include <iostream>
#include <stack>

using namespace std;

void repeat(const string, int);

int main() {
	stack<string> data;

	while(true) {
		string input;
		cout << "Enter a name : ";
		cin >> input;

		if(input.compare("q") == 0 || input.compare("exit") == 0 || input.compare("quit") == 0) break;

		data.push(input);
	}

	repeat("*", 20);

	while(!data.empty()) {
		cout << data.top() << endl;
		data.pop();
	}

	return 0;
}

void repeat(const string c, int times) {
	for(int i = 0 ; i < times; i++) {
		cout << c;
	}

	cout << endl;
}
