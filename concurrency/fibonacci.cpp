#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <unistd.h>

#include "fibonacci.h"

void job(int, int, FibonacciCache&);

std::mutex stdout_mtx;

int main() {
	FibonacciCache fib;
	std::vector<std::thread> threads;
	
	for(int i = 0; i < 2; i++) {
		threads.push_back(std::thread(job, i, 2, std::ref(fib)));
	}

	for(int i = 0; i < threads.size() ; i++) {
		threads[i].join();
	}

	return 0;
}

void job(int thread_id, int threads_count, FibonacciCache &fib) {
	for(int i = thread_id; i < 93 ; i+=threads_count) {
		unsigned long long int fib_i = fib.get(i);
		stdout_mtx.lock();
		std::cout << "Thread-" << thread_id << " : f(" << i << ") = " << fib_i << std::endl;
		stdout_mtx.unlock();
		sleep(1);
	}
}
