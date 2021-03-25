#include <iostream>
#include <chrono>

#include "sorts.h"
#include "utils.h"

#ifndef TAILLE
#define TAILLE 8
#endif

#ifndef MODE
#define MODE 1
#endif

int main () {
	int numbers[TAILLE], numbers_1[TAILLE], numbers_2[TAILLE], numbers_3[TAILLE], numbers_4[TAILLE], numbers_5[TAILLE];

	for(int i = 0; i < TAILLE ; i++) {
#if MODE == 1
		std::cout << "numbers[" << i << "] : " ;
#endif
		std::cin >> numbers[i] ;
	}	
	
	for(int i = 0; i < TAILLE ; i++) {
		numbers_1[i] = numbers[i] ; 
		numbers_2[i] = numbers[i] ; 
		numbers_3[i] = numbers[i] ; 
		numbers_4[i] = numbers[i] ; 
		numbers_5[i] = numbers[i] ; 
	}	
	
	/* Odd Even Merge Sort */	
	auto oems_start = std::chrono::steady_clock::now(); // Start Counter
	oddEvenMergeSort(numbers_5, 0, TAILLE);
	auto oems_end = std::chrono::steady_clock::now(); // Sort finished time
	// display time elapse
	colorize(32);
	std::cout << "[OEMS]"; colorize();
	std::cout << "\t\tSorted "; colorize(33);
	std::cout << TAILLE ; colorize();
	std::cout << " elements in " ; colorize(33);
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(oems_end - oems_start).count();
	std::cout << " ns\n"; 

	/* Insertion Sort */	
	auto insertion_start = std::chrono::steady_clock::now(); // Start counter 
	insertionSort(numbers_1,TAILLE);
	auto insertion_end= std::chrono::steady_clock::now(); // Sort finished time
	// display time elapse
	colorize(32);
	std::cout << "[Insertion]"; colorize();
	std::cout << "\tSorted " ; colorize(33);
	std::cout << TAILLE ; colorize();
	std::cout << " elements in " ; colorize(33);
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(insertion_end - insertion_start).count();
	std::cout << " ns\n";

	/* Bubble Sort */	
	auto bubble_start = std::chrono::steady_clock::now(); // Start counter 
	bubbleSort(numbers_4,TAILLE);
	auto bubble_end= std::chrono::steady_clock::now(); // Sort finished time
	// display time elapse
	colorize(32);
	std::cout << "[Bubble]"; colorize();
	std::cout << "\tSorted " ; colorize(33);
	std::cout << TAILLE ; colorize();
	std::cout << " elements in "  ; colorize(33);
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(bubble_end - bubble_start).count();
	std::cout << " ns\n";

	/* Merge Sort */	
	auto merge_start = std::chrono::steady_clock::now(); // Start counter
	mergeSort(numbers_2,0, TAILLE -1 );
	auto merge_end = std::chrono::steady_clock::now(); // Sort finished time
	// display time elapse
	colorize(32);
	std::cout << "[Merge]"; colorize();
	std::cout << "\t\tSorted "; colorize(33);
	std::cout << TAILLE ; colorize();
	std::cout << " elements in "; colorize(33);
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(merge_end - merge_start).count();
	std::cout << " ns\n";
	
	/* Bitonic Sort */	
	auto bitonic_start = std::chrono::steady_clock::now(); // Start Counter
	bitonicSort(numbers_3, 0, TAILLE, true);
	auto bitonic_end = std::chrono::steady_clock::now(); // Sort finished time
	// display time elapse
	colorize(32);
	std::cout << "[Bitonic]"; colorize();
	std::cout << "\tSorted "; colorize(33);
	std::cout << TAILLE ; colorize();
	std::cout << " elements in " ; colorize(33);
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(bitonic_end - bitonic_start).count();
	std::cout << " ns\n"; 

	colorize();	
	return 0;
}
