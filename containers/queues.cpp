#include <iostream>
#include <queue>
#include <list>

using namespace std;

void repeat(const string, int);

int main() {
	queue<string, list<string>> data;

	while(true) {
		string input;
		cout << "Enter a name : ";
		cin >> input;

		if(input.compare("q") == 0 || input.compare("exit") == 0 || input.compare("quit") == 0) break;

		data.push(input);
	}

	repeat("*", 50);

	while(!data.empty()) {
		cout << data.front() << endl;
		data.pop();
	}

	return 0;
}

void repeat(const string c, int times) {
	cout << endl;
	for(int i = 0 ; i < times; i++) {
		cout << c;
	}

	cout << endl;
}
