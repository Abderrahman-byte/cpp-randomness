#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
	vector<int> data;
	vector<thread> threads;
	mutex l;

	auto job = [&data, &l](int i, int a) {
		while(!data.empty()) {
			l.lock();
			cout << "[" << i << "] data = " << data.back() << ", a = " << a << endl;
			data.pop_back();
			l.unlock();
			usleep(1000);
		}
	};

	for(int i = 0; i < 10; i++) {
		data.push_back(rand());
	}
	
	for(int i = 0; i < 5; i++) {
		threads.push_back(thread(job, i, 9));
	} 

	for(int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}

	return 0;
}
