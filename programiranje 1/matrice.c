#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#define MAX_STR 10000

int maxm = 0, maxn = 0, maxsize[1000] = { 1 }, precision[1000] = { 0 };

int countDecimals(float num) {
    int decimalCount = 0;
    float x = num;
    while (x != (int)x) {
        x *= 10;
        decimalCount++;
        if (decimalCount > 10) break;
    }
    return decimalCount;
}

void swapVar(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void transpose(float matricaA[1000][1000], int *m,int *n) {
    for (int i = 0; i < *m; i++) {
        for (int j = i+1; j < *n; j++) {
            swapVar(&matricaA[i][j], &matricaA[j][i]);
        }
    }
    swapVar(m, n);
}

void maxSizePrecisionPerColumn(float matrix[1000][1000], int m, int n) {
    char t[100];
    for (int i = 0; i < n; i++) {
        printf("proslo");
        maxsize[i] = 1;
        precision[i] = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[j][i] != 0) {
                sprintf(t, "%d", (int)matrix[j][i]);
                if (maxsize[i] < strlen(t))maxsize[i] = strlen(t);

                int decimalCount = countDecimals(matrix[j][i]);
                if (precision[i] < decimalCount)precision[i] = decimalCount;
            }
        }
    }
}

void getSubstring(int indx, int len, char string[], char substring[]) {
    for (int i = indx; i < (indx + len); i++) {
        substring[i - indx] = string[i];
    }
    substring[len] = '\0';
}

void getRed(char red[MAX_STR], char substr[MAX_STR], float matricaA[1000][1000], int *rows, int *col) {
    int indx = 0;
    *col = 0;

    for (int i = 0; i < strlen(red); i++) {
        if (red[i] == ' ' || red[i] == '\0' || red[i] == '\n') {
            if (red[i-1]!=' ' && i!=0){
            getSubstring(indx, i - indx, red, substr);
            matricaA[*rows][*col] = atof(substr);
            (*col)++;
            indx = i;
            }
        }
    }
    if (*col > maxn)maxn = *col;
}

void upisMatrice(float matrica[1000][1000], int *rows,int *col) {
    char red[MAX_STR], substr[MAX_STR];

    while (1) {
        fgets(red, MAX_STR, stdin);

        if (strlen(red) == 1 && red[0] == '\n') {
            break;
        }
        *col = 0;
        getRed(red, substr, matrica, rows, col);
        (*rows)++;
    }

    if (*rows > maxm)maxm = *rows;

    *rows = maxm;
    *col = maxn;
    maxm = 0;
    maxn = 0;
}

void printMatrix(float matrix[1000][1000], int *rows, int *cols) {
    int m = *rows,n=*cols;
    maxSizePrecisionPerColumn(matrix, m, n);
    printf("2");
    printf("|----\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            if (j == 0)printf("|");

            printf("%*.*f  ",maxsize[j], precision[j], matrix[i][j]);
        }
        printf("\n"); 
    }
    printf("|----\n\n");
}

void echelonForm(float matrix[1000][1000], int m) {
    float required_ratio = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = m - 1; j > i; j--) {
            printf("\ni,j: %d %d %.0f %.0f", i, j, matrix[j][i], matrix[j - 1][i]);
            if (matrix[j][i] == 0) continue;

            if (matrix[j - 1][i] != 0) {
                required_ratio = matrix[j][i] / matrix[j - 1][i];
            }
            else {
                printf("1");
                for (int x = 0; x < m; x++) {
                    swapVar(&matrix[j][x], &matrix[j - 1][x]);
                }
                printf("2");
                continue;
            }

            for (int k = 0; k < m; k++) {
                matrix[j][k] = matrix[j][k] - required_ratio * matrix[j - 1][k];
            }
        }
    }
}


void determinanta(float matrix[1000][1000], int m, int n) {
    if (m != n) { printf("Racunanje determinante nije moguce jer matrica nije kvadratna\n"); return; }
    echelonForm(matrix,m);
    printf(".");
    printf("|----\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0)printf("|");

            printf("%*.*f  ", maxsize[j], precision[j], matrix[i][j]);
        }
        printf("\n");
    }
    printf("|----\n\n");

    printMatrix(matrix,m,n);
    printf("no determinant 4 u");
}


void matrice() {
    float(*matricaA)[1000] = calloc(1000, sizeof(float[1000]));
    float(*matricaB)[1000] = calloc(1000, sizeof(float[1000]));

    char func,mat;
    int m = 0, n = 0, p = 0, q = 0;

    printf("Upisi matricu A redak po redak, za kraj klikni enter\n");

    upisMatrice(matricaA,&m,&n);
    printMatrix(matricaA,&m,&n);
    echelonForm(matricaA, m);
    printMatrix(matricaA, m, n);

    printf("Zelite li upisati drugu matricu? y/n\n");
    scanf(" %c", &func);
    if (func == 'y') {
        while (getchar() != '\n');
        upisMatrice(matricaB, &p, &q);
        printMatrix(matricaB, &p, &q);
    }

    while (func != '-') {
        printf("Upisite komandu operacije, a i b su matrice te ta slova idu prva, onda ide funkcija ( determinanta(d) ), npr. ad ce ispisati determinantu matrice a\n");
        scanf(" %c%c", &mat,&func);

        switch (func) {
        case 'd':
            switch (mat) {
            case 'a':
                determinanta(matricaA, m, n);
            }
        default:printf("Pogresno upisana komanda");
        }
    }
    printf("Exited...\n");

    free(matricaA);
    free(matricaB);
    return 0;
}