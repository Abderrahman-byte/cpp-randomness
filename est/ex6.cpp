#include <iostream>

int main () {
	int i, j , n;

	i = 0;
	n = i++;
	std::cout << "A : i = " << i << "\tn = " << n << std::endl;

	i = 10;
	n = ++i;
	std::cout << "B : i = " << i << "\tn = " << n << std::endl;
	
	i = 20;
	j = 5;
	n = i++ * ++j;
	std::cout << "C : i = " << i << "\tj = " << j << "\tn = " << n << std::endl;

	i = 15;
	n = i += 3 ;
	std::cout << "D : i = " << i << "\tn = " << n << std::endl;

	i = 3;
	j = 5;
	i *= --j;
	std::cout << "E : i = " << i << "\tj = " << j << "\tn = " << n << std::endl;

	return 0;
}
