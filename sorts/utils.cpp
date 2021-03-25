#include <iostream>
#include <string>
#include <sstream>

void printArray(int array[], int cout) {
	for(int i = 0; i < cout ; i++)
		std::cout << array[i] << '\t';

	std::cout << std::endl;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void colorize(int code = 0) {
	std::string code_str;
       	std::stringstream ss;

	ss << code ;
	ss >> code_str;

	std::cout << "\033[0;"<< code << "m";
}
