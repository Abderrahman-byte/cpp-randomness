#include <iostream>
using namespace std;

template <typename T>
void Swap(T *a, T *b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template <typename T>
void Display(T a, T b) {
	cout << "a : " << a << ", b : " << b << endl;
}

int main() {
	int a, b;
	a = 10;
	b = 3;
		
	Display(a, b);
	Swap(&a, &b);
	Display(a, b);

	char c, d;
	c = 'E';
	d = 'A';


	Display(c, d);
	Swap(&c, &d);
	Display(c, d);
}
