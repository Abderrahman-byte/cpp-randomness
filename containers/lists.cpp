#include <iostream>
#include <sstream>
#include <list>

#define ZERO_ASCII 48

using namespace std;

int strToInt(string);
bool isDigit(string);
void sortData(list <int>);

int main() {
	list<int> data;

	while(1) {
		string input;
		cout << "Enter a integer : ";
		cin >> input;
		
		if(input.compare("exit") == 0 || input.compare("quit") == 0 || input.compare("q") == 0) break;

		if(!isDigit(input)) cerr << "[ERROR] \"" << input << "\" is not a number" << endl;
		else {
			data.push_back(strToInt(input));	
		}
	}
	
	data.sort();
	while(!data.empty()) {
		cout << data.front() << endl;
		data.pop_front();
	}

	return 0;
}

int strToInt(string str) {
	int n = 0;
	stringstream num(str);
	num >> n;
	return n;
}

bool isDigit(string num) {
	for(int i = 0; i < num.length(); i++) 
		if((int)num[i] < ZERO_ASCII || (int)num[i] > ZERO_ASCII + 9) 
			return false;
	
	return true;
}
