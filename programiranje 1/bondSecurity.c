#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define PREDMETIM 6;
#define PREDMETIN 6;

char** inputMatrixBondSec(int m,int n) {
	char** mat = malloc(m * sizeof(char*));
	for (int i = 0; i < m; i++) mat[i] = malloc(n * sizeof(char));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)scanf(" %c", &mat[i][j]);
	}

	return mat;
}

void printBondSec(char** mat, int m, int n) {
	//printf("\n\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			//printf("%c", mat[i][j]);
		}
		//printf("\n");
	}
}

void freeMatrixBondSec(char** mat,int m) {
	for (int i = 0; i < m; i++) {
		free(mat[i]);
	}
	free(mat);
}

void swapDashes(char** mat,int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == '|')mat[i][j] = '-';
			else if (mat[i][j] == '-')mat[i][j] = '|';
		}
	}
}

void transposeBondSec(char*** mat, int rezM,int rezN) {
	char** transposed = malloc(rezN * sizeof(char*));
	for (int i = 0; i < rezN; i++)transposed[i] = malloc(rezM * sizeof(char));

	for (int i = 0; i < rezN; i++) {
		for (int j = 0; j < rezM; j++) {
			transposed[i][j] = (*mat)[j][i];
		}
	}
	freeMatrixBondSec(*mat, rezM);
	*mat = transposed;
}

char** trim(char **mat, int* rezM, int* rezN) {
	int startM = 0;
	int endM = *rezM;
	int preslo = 0;

	for (int i = 0; i < *rezM; i++) {
		int isEmpty = 1;
		for (int j = 0; j < *rezN; j++) {
			if (mat[i][j] != '.') {
				isEmpty = 0;
				break;
			}
		}
		if (isEmpty) {
			if (!preslo) startM++;
			else endM--;
		}else preslo = 1;
	}

	//traspose the matrix so that we can detect empty spots easier
	////printf("Transposing 1:\n");
	transposeBondSec(&mat, *rezM, *rezN);
	
	int startN = 0;
	int endN = *rezN;
	preslo = 0;

	for (int i = 0; i < *rezN; i++) {
		int isEmpty = 1;
		for (int j = 0; j < *rezM; j++) {
			if (mat[i][j] != '.') {
				isEmpty = 0;
				break;
			}
		}
		if (isEmpty) {
			if (!preslo) startN++;
			else endN--;
		}
		else preslo = 1;
	}

	//traspose the matrix again so we can properly copy
	////printf("Transposing 2:\n");
	transposeBondSec(&mat, *rezN, *rezM);

	*rezM = endM - startM;
	*rezN = endN - startN;

	char** trimmedMat = malloc(*rezM * sizeof(char*));
	for (int i = 0; i < *rezM; i++) {
		trimmedMat[i] = malloc(*rezN * sizeof(char));
	}

	for (int i = startM; i < endM; i++) {
		for (int j = startN; j < endN; j++) {
			trimmedMat[i - startM][j - startN] = mat[i][j];
		}
	}

	return trimmedMat;
}

char** rotate90(char** mat, int *m, int *n) {
	char** tempMat = malloc(*n * sizeof(char*));
	for (int i = 0; i < *n; i++) tempMat[i] = malloc(*m * sizeof(char));

	for (int i = 0; i < *m; i++) {
		for (int j = 0; j < *n; j++) {
			tempMat[j][*m - 1 - i] = mat[i][j];
		}
	}
	int t = *m;
	*m = *n;
	*n = t;

	swapDashes(tempMat,*m,*n);	

	return tempMat;
}

int findIndexOfCharacterInFirstRow(char** predmet, int pN) {
	for (int i = 0; i < pN; i++) {
		if (predmet[0][i] != '.')return i;
	}
}

int checkForItem(char** predmet, int indx,int pM,int pN, char** mat, int iM,int jM) {
	int x = 1;
	//printf("print this:\n");
	for (int i = iM; i < pM+iM; i++) {
		for (int j = jM-indx; j < pN + jM-indx; j++) {
			if (mat[i][j] != predmet[i - iM][j - jM + indx] && predmet[i - iM][j - jM + indx] != '.')x = 0;;
			//printf("%c", mat[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");
	if (!x)return 0;
	return 1;
}

int locate(char** mat, int m, int n, char** predmet, int pM, int pN) {
	if (pM > m || pN > n) {
		return 0;
	}
	int indx = findIndexOfCharacterInFirstRow(predmet, pN);
	//printf("indx: %d\ncharactaer: %c\n", indx, predmet[0][indx]);
	//printf("%d-%d>n-pN=%d	%d-%d>m-pM=%d\n", n, pN, n - pN,m,pM,m-pM);
	for (int i = 0; i <= m - pM; i++) {
		for (int j = indx; j <= n - pN+1; j++) {
			if (mat[i][j] == predmet[0][indx]) {
				//printf("\nchecking for %c on %d %d\n", mat[i][j],i,j);
				int t = checkForItem(predmet, indx, pM, pN, mat, i, j);
				if (t == 1)return 1;
			}

		}
	}
	return 0;
}

void main() {
	int opasnost[11];
	opasnost[0] = 0;
	int m, n;
	scanf("%d %d", &m, &n);
	char** mat=inputMatrixBondSec(m, n);

	int k;
	scanf("%d", &k);

	char*** predmeti = malloc(k * sizeof(char**));
	for (int i = 0; i < k; i++) {
		int rezM = PREDMETIM;
		int rezN = PREDMETIN;
		
		predmeti[i] = inputMatrixBondSec(rezM, rezN);
		char** trimmedPredmet= trim(predmeti[i], &rezM, &rezN);
		predmeti[i] = trimmedPredmet;
		
		for (int r = 0; r < 4; r++) {
			//printf("\nPokusaj pronalaska :%d\n", r + 1);
			int t = locate(mat, m, n, predmeti[i], rezM, rezN);
			printBondSec(mat, m, n);
			printBondSec(predmeti[i], rezM, rezN);
			if (t == 1) {
				opasnost[++opasnost[0]] = i + 1;
				for (int x = 0; x < 4 - r; x++) { 
					char** rotated = rotate90(mat, &m, &n); 
					freeMatrixBondSec(mat, n);
					mat = rotated;
				}
				break;
			}
			else {
				char** rotated = rotate90(mat, &m, &n);
				freeMatrixBondSec(mat, n);
				mat = rotated;
			}
		}
		//printf("\nUkupno opasnosti\n", opasnost[0]);
		//for (int x = 1; x <= opasnost[0]; x++)printf("%d ", opasnost[x]);
	}
	if (opasnost[0] > 0) {
		printf("Opasni predmeti:");
		for (int x = 1; x <= opasnost[0]; x++)printf(" %d", opasnost[x]);
		printf("\nVODI GA!");
	}
	else printf("Mozete proci.");
	
	//free memory
	freeMatrixBondSec(mat, m);
	for (int x = 0; x < k; x++) {
		for (int i = 0; i < 6; i++) {
			free(predmeti[x][i]);
		}
		free(predmeti[x]);
	}
	free(predmeti);
}