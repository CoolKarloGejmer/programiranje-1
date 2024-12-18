#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char** defSahovskaPlocaZaDame(char** mat, int m, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((j + i) % 2 == 0) {
				mat[j][i] = 'O';
			}
			else if (j == 0 || j == 1)mat[j][i] = 'C'; //ploca za dame
			else if (j == m - 1 || j == m - 2)mat[j][i] = 'B';
			else mat[j][i] = 'X';
		}

	}
	return mat;
}

void SahovskaPlocaZaDame() {
	int m, n;
	scanf("%d %d", &m, &n);

	char** mat = malloc(m * sizeof(char*));
	for (int i = 0; i < m; i++)mat[i] = malloc(n * sizeof(char));

	mat = defSahovskaPlocaZaDame(mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)printf("%c", mat[i][j]);
		printf("\n");
	}

	free(mat);
}