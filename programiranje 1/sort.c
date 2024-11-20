#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void swap(char *x, char *y) {
	char t=*x;
	*x = *y;
	*y = t;
}

void selectionSort(char x[40]) {
	int indx;

	for (int i = 0; i < 39; i++) {
		indx = i;

		for (int j = i+1; j < 40; j++) {
			if (x[indx] > x[j])indx = j;
		}

		swap(&x[i], &x[indx]);
	}
}

void bubbleSort(char x[40]) {
	for (int i = 0; i < 39; i++) {
		for (int j = 0; j < 39-i; j++) {
			if (x[j] > x[j+1])swap(&x[j], &x[j+1]);
		}
	}
}

void sortAlgoritmi() {
	int r;
	char lista[40];
	srand(time(0)); //postavlja seeda rand() funkcije, inace je default seed
	for (int i = 0; i < 40; i++) {
		r = rand() % 57;
		lista[i] = (char)r + 'A';
	}
	printf("Nesortirana lista:\n");
	for (int i = 0; i < 40; i++)printf("%c ",lista[i]);

	bubbleSort(lista);
	printf("\n\nSortirana lista:\n");
	for (int i = 0; i < 40; i++)printf("%c ", lista[i]);
}