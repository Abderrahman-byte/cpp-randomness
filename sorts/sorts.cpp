#include "utils.h"
#include <iostream>

/* INSERTION */
void insertionSort(int array[], int count) {
	for(int i = 1; i < count; i++) {
		int key = array[i];
		int j = i - 1;

		while(j >= 0 && array[j] > key) {
			array[j + 1] = array[j] ;
			j--;
		}

		array[j + 1] = key;
	}
	
}

/* MERGE SORT */
void merge(int arr[], int l, int m, int r) {
	int k, s, i;
	int len_l = m - l + 1;
	int len_r = r - m;

	int L[len_l], R[len_r];

	for (int i = 0; i < len_l; i++)
		L[i] = arr[l + i];

	for (int j = 0; j < len_r; j++)
		R[j] = arr[m + 1 + j];

	s = k = 0;
	i = l;

	while (k < len_l && s < len_r) {
		if (L[k] <= R[s]) {
			arr[i] = L[k];
			k++;
		}
		else {
			arr[i] = R[s];
			s++;
		}
		i++;
	}

	while (k < len_l) {
		arr[i] = L[k];
		k++;
		i++;
	}

	while (s < len_r) {
		arr[i] = R[s];
		s++;
		i++;
	}
}

void mergeSort(int array[], int l, int r ) {
	if(l < r) {
		int m = l + (r - l) / 2;

		mergeSort(array, l, m);
		mergeSort(array, m + 1, r);

		merge(array, l, m, r);
	}	
}


/* BITONIC SORT */
void bitonicMerge(int arr[], int l, int size, bool direction) {
	if(size > 1) {
		int hup = size / 2;

		for(int i = l; i < l + hup; i++) {
		bool shouldSwap = (direction && arr[i] > arr[i + hup]) || (!direction && arr[i] < arr[i + hup]) ;
			
			if(shouldSwap) swap(arr[i], arr[i + hup]);
		}

		bitonicMerge(arr, l, hup, direction);
		bitonicMerge(arr, l + hup, hup, direction);
	}
}

void bitonicSort(int arr[], int l, int size, bool direction) {
	if(size > 1) {
		int s = size / 2;

		bitonicSort(arr, l, s, true);
		bitonicSort(arr, l + s, s, false);

		bitonicMerge(arr, l, size, direction);
	}
}

/* BUBBLE SORT */
void bubbleSort(int array[], int size) {
	bool sorted = false;

	while(!sorted) {
		sorted = true;

		for(int i = 0; i < size - 1 ; i++) {
			if(array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				sorted = false;
			}
		}
		
	}
}

/* ODD EVEN MERGE SORT */
void oddEvenMerge(int array[], int low, int size, int r) {
	int m = r * 2;

	if(m < size) {
		oddEvenMerge(array, low, size, m); 
		oddEvenMerge(array, low + r, size, m); 
		for(int i = low + r; i + r < low + size; i+=m) {
			if(array[i] > array[i + r]) swap(array[i], array[i + r]);
		}
	} else if(array[low] > array[low + r]) swap(array[low], array[low + r]);

}

void oddEvenMergeSort(int array[], int low, int size) {
	if(size > 1) {
		int m = size / 2;
		oddEvenMergeSort(array, low, m);	
		oddEvenMergeSort(array, low + m, m);
		oddEvenMerge(array, low, size, 1);
	}
}
