#include <iostream>
#include <thread>
#include <fstream>

#include <cstdlib>
#include <unistd.h>

using namespace std;


void job() {
	ofstream file;
	file.open("./data");

	for(int i = 0; i < 10; i++)
	{	
		cout << "[" << this_thread::get_id() << "] I a thread " << i << endl;
		file << "[" << this_thread::get_id() << "] I a thread " << i << endl;
		sleep(1);
	}

	file.close();
}

int main() {
	cout << "START: " << getpid() << " tread id : " << this_thread::get_id() << endl;
	thread t1(job);
	t1.detach();
	
	for(int i = 0; i < 15; i++) {
		cout << "." << endl;
		sleep(1);
	}

	return 0;
}
