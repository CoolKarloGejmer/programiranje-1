#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

void printLab4(char **matrix,int m,int n) {
	printf("\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}

void upisMatrix(char** matrix, int m, int n) {
	char str[500];

	for (int i = 0; i < m; i++) {
		fgets(str, 500, stdin);

		for (int j = 0; j < n; j++) {
			matrix[i][j] = str[j];
		}
	} 
	matrix[0][0] = '#';
}

void transposeMatrix(char*** matrix,int* m, int *n) {
	int row = *m;
	int col = *n;

	char** trans = malloc(col * sizeof(char*));
	for (int i = 0; i < col; i++) {
		trans[i] = malloc(row * sizeof(char));
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			trans[j][i] = (*matrix)[i][j];
		}
	}

	for (int i = 0; i < row; i++) {
		free((*matrix)[i]);
	}
	free(*matrix);

	*matrix = trans;
	*m = col;
	*n = row;
}

int red(char *red, int *e,int n){
	int xcount = 2;//moving the first x requires 2 energy, 2nd 3energy, 3rd 4e...
	int energy = *e;
	
	for (int j = 0; j < n-1; j++) {
		if (energy == 0) {
			return 1;
		}

		if (red[j + 1] == '.' && energy>0) {
			red[j] = '.';
			red[j + 1] = '#';
			energy--;
		}
		else if (red[j + 1]=='x' && energy>=xcount) {
			red[j] = '.';
			red[j + 1] = '#';
			energy -= xcount;
			xcount++;
		}
		else if (red[j + 1] == 'x' && energy < xcount) {
			printf("this");
			*e = energy;
			return 1;
		}
		printf("\ntransormacija %d:   ", j + 1);
		for (int i = 0; i < n; i++)printf("%c", red[i]);
		printf("    e-nakon trans: %d",energy);
	}

	for (int j = n-1; j > 0; j--) {
		if (energy > 0) {
			red[j] = '.';
			red[j - 1] = '#';
			energy--;
		}
		printf("\ntransormacija %d:   ", j + 1);
		for (int i = 0; i < n; i++)printf("%c", red[i]);
		printf("    e-nakon trans: %d", energy);
	}

	*e = energy;
	return 0;
}

void lab4() {
	int m, n, e,next=0;

	scanf("%d %d %d", &m, &n, &e);
	getchar();
	//allocate memory for matrix
	char** matrix = malloc(m* sizeof(char*));
	for (int i = 0; i < m; i++) {
		matrix[i] = malloc(n * sizeof(char));
	}

	upisMatrix(matrix, m, n);
	matrix[0][0] = '#';
	transposeMatrix(&matrix, &m, &n);
	
	for (int row = 0; row < m; row++) {
		printf("\n%d %d   ", row + 1,e);
		printf("prije:");
		printLab4(matrix, m, n);
		next = red(matrix[row], &e, n);

		if (e > 0 && matrix[m - 1][0] == '#' && matrix[m - 1][1] == '.') {
			printf("\n\n\nenergy exceeds needs\n\n\n");
			break;
		}

		if (e > 0 && next==0) {
			matrix[row][0] = '.';
			matrix[row + 1][0] = '#';
			e--;
		} 
		else if (next == 1) {
			break;
		}
		printf("\n\nposlije:");
		printLab4(matrix, m, n);
	}
	printf("\n%d", e);
	transposeMatrix(&matrix, &m, &n);
	printLab4(matrix, m, n);
	//free memory from matrix
	for (int i = 0; i < m; i++) {
		free(matrix[i]);
	}
	free(matrix);
}