#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void freeMatrix(int** mat, int m) {
	for (int i = 0; i < m; i++) {
		free(mat[i]);
	}
	free(mat);
}

void printMnozenjeMatrica(int** mat,int m,int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

int** upisMnozenjeMatrica(int m, int n) {
	int** temp = malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		temp[i] = malloc(n * sizeof(int));
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &temp[i][j]);
		}
	}

	return temp;
}

int** mnozenjeMatrica(int** matA,int m,int n, int** matB,int p,int q) {
	if (n != p) {
		printf("Matrice nisu ulancane\n");
		return;
	}

	int** temp = malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		temp[i] = malloc(q * sizeof(int));
	}
	int zbr = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < q; j++) {
			zbr = 0;
			for (int element = 0; element < n; element++) {
				zbr += matA[i][element] * matB[element][j];
			}
			temp[i][j] = zbr;
		}
	}

	return temp;
}

void mnozenjeMatricaZadatak() {
	int m, n, p, q;

	scanf("%d %d", &m, &n);
	int** matricaA = upisMnozenjeMatrica(m, n);

	scanf("%d %d", &p, &q);
	int** matricaB = upisMnozenjeMatrica(p, q);

	printf("\n\nMatricaA:\n");
	printMnozenjeMatrica(matricaA, m, n);

	printf("\n\nMatricaB:\n");
	printMnozenjeMatrica(matricaB, p, q);

	int** rez = mnozenjeMatrica(matricaA,m,n, matricaB,p,q);
	printf("\n\nRezultat:\n");
	printMnozenjeMatrica(rez, p, q);

	freeMatrix(matricaA,m);
	freeMatrix(matricaB,p);
	freeMatrix(rez,m);
}