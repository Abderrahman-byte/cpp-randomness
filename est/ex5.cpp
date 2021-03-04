#include <iostream>

int main () {
	int n = 10, p = 5, q = 10, r;
	
	r = n == (p = q);
	std::cout << "A : n = " << n << " p = " << p << " q = " << q << " r = " << r << std::endl;
	
	n = p = q = 5;
	n += p += q;
	std::cout << "B : n = " << n << " p = " << p << " q = " << q << " r = " << r << std::endl;
	
	q = n < p ? n++ : p++;
	std::cout << "C : n = " << n << " p = " << p << " q = " << q << " r = " << r << std::endl;
	
	q = n > p ? n++ : p++;
	std::cout << "D : n = " << n << " p = " << p << " q = " << q << " r = " << r << std::endl;

	return 0;
}
