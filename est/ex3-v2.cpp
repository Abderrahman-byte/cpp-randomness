#include <iostream>

void swap(int &, int &);

int main () {
	int a, b, c;

	std::cout << "Enter a : ";
	std::cin >> a;	

	std::cout << "Enter b : ";
	std::cin >> b;	

	std::cout << "Enter c : ";
	std::cin >> c;

	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	
	swap(a, b);
	swap(a, c);

	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;

	return 0;
}

void swap(int &a, int &b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
