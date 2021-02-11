#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef map<string, string> userd_t;

void repeat(const string, int);
void getUserData(userd_t &);
void printUsage();
void displayUser(userd_t);

int main() {
	vector<userd_t> users_data;
	
	while(true) {
		int cmd;
		printUsage();

		cout << ">> ";
		cin >> cmd;
		
		switch(cmd) {
			case 1: {
				userd_t user;
				getUserData(user);
				users_data.push_back(user);
				}
				break;
			case 3:
				exit(2);
				break;
			case 2:
				for(int i = 0; i < users_data.size(); i++) displayUser(users_data[i]);
				break;

		}
	}

	return 0;
}

void printUsage() {
	cout << "[*] Type command number" << endl;
	cout << "[1] Add new user" << endl;
	cout << "[2] List users" << endl;
	cout << "[3] quit" << endl;
	cout << endl ;
}

void getUserData(userd_t &user) {
	cout << "Enter user full name : ";
	cin >> user["first_name"];
	cin >> user["last_name"];
	cout << "Enter user password : ";
	cin >> user["password"];
	cout << "Enter user's age : ";
	cin >> user["age"];	
}

void repeat(const string str, int c) {
	for(int i = 0; i < c; i++) cout << str;
	
	cout << endl;
}

void displayUser(userd_t user) {
	repeat("*", 30);
	cout << "username : " << user["first_name"] << " " << user["last_name"] << endl;
	cout << "password : " << user["password"] << endl;
	cout << "age : " << user["age"] << endl << endl;
}
