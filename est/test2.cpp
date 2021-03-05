#include <iostream>

int main () {
	int time = 21;
	std::cout << (time < 10 ? "Good Morning" : (time < 20 ? "Good Day" : "Good Evening")) << std::endl; 
	return 0;
}
