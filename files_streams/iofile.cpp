#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

typedef map<string, string> userd_t;

void repeat(const string, int);
void getUserData(userd_t &);
void printUsage();
void displayUser(userd_t);
void writeToFile(string, vector<userd_t>);

int main() {
	vector<userd_t> users_data;
	string path_output = "./data.json";
	
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
			case 4:
				exit(1);
				break;
			case 2:
				for(int i = 0; i < users_data.size(); i++) displayUser(users_data[i]);
				break;
			case 3:
				writeToFile(path_output, users_data);
				exit(1);
				break;

		}
	}

	return 0;
}

void printUsage() {
	cout << "[*] Type command number" << endl;
	cout << "[1] Add new user" << endl;
	cout << "[2] List users" << endl;
	cout << "[3] Write data to file and exit" << endl;
	cout << "[4] quit" << endl;
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

void oTabs(ofstream &file, int n = 1) {
	for(int i = 0; i < n; i++) file << "\t";
}

void writeToFile(string path, vector<userd_t> data) {
	ofstream file;
	file.open(path);

	if(file.is_open()) {
		file << "[" << endl;
		
		for(int i = 0; i < data.size(); i++) {
			oTabs(file, 1);
			file << "{" << endl;


			oTabs(file, 2);
			file << " \"usersname\" : \"" << data[i]["first_name"] << " " << data[i]["last_name"] << "\"," << endl;
			oTabs(file, 2);
			file << " \"password\" : \"" << data[i]["password"] <<  "\"," << endl;
			oTabs(file, 2);
			file << " \"age\" : " << data[i]["age"] <<  "" << endl;


			oTabs(file, 1);
			file << "}";
			if(i == data.size() - 1) file << endl;
			else file << "," << endl;
		}
		
		file << "]" << endl;

		file.close();
	} else {
		cerr << "[ERROR] Couldn't open file " << path << endl; 
	}
}
