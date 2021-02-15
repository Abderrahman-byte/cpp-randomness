#include <iostream>
#include <future>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <unistd.h>

unsigned int randomize();

int main() {
	time_t start = time(NULL);
	std::future<unsigned int> r = std::async(std::launch::async, randomize);
	
	std::cout << "I am doing some stuff, none of your business" << std::endl;
	sleep(3);
	std::cout << "business done" << std::endl;

	std::cout << "LETS r.get()" << std::endl;
	std::cout << r.get()  << std::endl;
	
	time_t end = time(NULL);

	std::cout << "Time : " << end - start << std::endl; 
	return 0;
}

unsigned int randomize() {
	std::cout << "START RANDOM()" << std::endl;

	static unsigned int x_n =  rand();
	static unsigned int m = rand() % INT_MAX >> 2 << 1;

	const int a = rand() % 100 >> rand() % 2;
	const int b = rand() % 100 << rand() % 2;

	unsigned int x_n1 = (a * x_n + b) % m;
	x_n = x_n1;
	
	usleep((a * b * 1000) % (3 * 1000 * 1000));
	
	return x_n;
}
