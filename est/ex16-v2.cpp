#include <iostream>

#define TAILLE 11

void sort(int *, int);
template <typename T> void swap(T*, T*);
int search(int *, int, int);
int cell(float );

int main () {
	int numbers[TAILLE]; int v;

	for(int i = 0; i < TAILLE; i++) {
		std::cout << "Entrez entier numbers[" << i << "] : " ;
		std::cin >> numbers[i];
	}

	sort(numbers, TAILLE);
	
	for(int i = 0; i < TAILLE; i++) {
		std::cout << numbers[i] << std::endl;
	}

	std::cout << "q = numbers[" << search(numbers, 8, TAILLE) << "] = " << numbers[search(numbers, 8, TAILLE)] << std::endl;
	return 0;
}

void sort(int *n, int count) {
	for(int i = 0; i < count - 1; i++) {
		for(int j = i + 1; j < count; j++) 
			if(n[j] < n[i]) swap(&n[i], &n[j]) ;
		
	}
}

template <typename T> void swap(T *a, T *b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

int search(int *n, int q, int cout) {
	int index = -1;
	int middle = cell((float)cout / 2.00);
	int steps = cell((float)(cout - middle + 1) / 2.00);
	
	while(middle < cout && index == -1 && middle >= 0) {
		if(n[middle] > q) middle -= steps ;
	     	else if(n[middle] < q) middle += steps;
		else index = middle;

		steps = cell((float)(cout - middle + 1) / 2.00);
	}

	return index;
}

int cell(float n) {
	if((int)n == n) return (int)n;
	else return (int)(n + 1); 
}
