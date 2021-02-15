#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

#include <unistd.h>

void job1(int, std::vector<int>&);
void job2(int, std::vector<int>&);

std::mutex stdio_lock;
std::mutex stack_lock;

int main() {
	const unsigned int THREADS_NUM = std::thread::hardware_concurrency();
	std::vector<int> randlist;
	std::vector<std::thread> threads;

	for(int i = 0; i < THREADS_NUM; i++) {
		if(i == 0) threads.push_back(std::thread(job1, i, std::ref(randlist)));
		else threads.push_back(std::thread(job2, i, std::ref(randlist)));
	} 

	for(int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}

	return 0;
}

void job1(int i, std::vector<int> &randlist) {
	int a = 1;

	while(true) {
		stack_lock.lock();
		randlist.push_back(a);
		stack_lock.unlock();

		a++;
		usleep(1000 * 1000 / 3);
	}
}

void job2(int i, std::vector<int> &randlist) {
	while(true) {
		bool stack_empty;

		stack_lock.lock();
		stack_empty = randlist.empty();
		
		if(stack_empty) {
			stack_lock.unlock();
		} else {
			int stack_size = randlist.size() - 1;
			int value = randlist.back();
			randlist.pop_back();
			stack_lock.unlock();

			stdio_lock.lock();
			std::cout << "[THREAD-" << i << "] value from vector : " << value ; 
			std::cout << ", remain size : " << stack_size << std::endl;
			stdio_lock.unlock();
		}

		sleep(1);
	}
}
