#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

void callback(int i) {
		cout << "We are watching you " << "Abderrahmane" << endl;
		exit(0);
}

int main() {
	string name = "Abderrahmane";
	
	cout << getpid() << endl ;
	signal(SIGINT, callback);
	signal(SIGTERM, callback);
	
	while(true) {}
	return 0;
}
