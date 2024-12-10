#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int** upis2DIzbori(int m,int n) {
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

void print2DIzbori(int** mat, int m, int n) {
	printf("\n\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

int maxRedStupac(int** mat, int i,int redstupac,int m,int n) {
	int zbr = 0;
	if (redstupac == 0) { //run this ako je za retke
		for (int j = 0; j < n; j++) zbr += mat[i][j];
	}
	else if (redstupac == 1) { //run this ako je za stupce
		for (int j = 0; j < m; j++) zbr += mat[j][i];
	}
	return zbr;
}

void izbori2D() {
	int m, n;
	scanf("%d %d", &m, &n);
	int** matR = upis2DIzbori(m, n);
	int** matD = upis2DIzbori(m, n);

	int** maxRed = malloc(2 * sizeof(int*));//2 redka je zbroj po redku za ronalda/drugog kandidata
	for(int i=0;i<2;i++){
		maxRed[i] = malloc(n * sizeof(int));
	}
	int** maxStupac = malloc(2 * sizeof(int*));//2 redka je zbroj po stupcu za ronalda/drugog kandidata
	for (int i = 0; i < 2; i++) {
		maxStupac[i] = malloc(m * sizeof(int));
	}

	for (int i = 0; i < m; i++) {
		maxRed[0][i] = maxRedStupac(matR, i, 0, m, n);
		maxRed[1][i] = maxRedStupac(matD, i, 0, m, n);
	}
	for (int i = 0; i < n; i++) {
		maxStupac[0][i] = maxRedStupac(matR, i, 1, m, n);
		maxStupac[1][i] = maxRedStupac(matD, i, 1, m, n);
	}

	float maxRatio=0;
	int redStupac=0, indx;
	for (int i = 0; i < m; i++) {
		if (maxRatio < (float)maxRed[0][i] / maxRed[1][i]) {
			maxRatio = (float)maxRed[0][i] / maxRed[1][i];
			indx = i + 1;
			redStupac = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (maxRatio < (float)maxStupac[0][i] / maxStupac[1][i]) {
			maxRatio = (float)maxStupac[0][i] / maxStupac[1][i];
			indx = i + 1;
			redStupac = 1;
		}
	}

	if (redStupac == 0)printf("Najbolje je ukloniti %d. red iz tablica.",indx);
	else if (redStupac == 1)printf("Najbolje je ukloniti %d. stupac iz tablica.",indx);
}