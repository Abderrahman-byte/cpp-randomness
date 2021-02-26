#include <iostream>

template <typename T> void swap(T&, T&);

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

template <typename T> 
void swap(T &a, T &b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
