#include <stdio.h>

int age_1;
int age_2;
int age_3;

int* getAgeP(int);

int main () {
	for(int i = 1; i <= 3; i++) {
		printf("Enter age_ %d : ", i);
		scanf("%d", getAgeP(i));
	}
	
	printf("Age 1 = %d\n", age_1);
	printf("Age 2 = %d\n", age_2);
	printf("Age 3 = %d\n", age_3);
	return 0;
}

int* getAgeP(int i) {
	switch(i) {
		case 2:
			return &age_2;
		case 3:
			return &age_3;
		default :
			return &age_1;
	}
}
