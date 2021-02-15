#include <iostream>
#include <thread>

#define THREADS_NUMBER std::thread::hardware_concurrency() 

int main() {
	const unsigned int threads = std::thread::hardware_concurrency();
	std::cout << THREADS_NUMBER << std::endl ;

	return 0;
}
