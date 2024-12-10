#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void selectionSortHistogramPostotaka(int* arr, int n) {
    int min_index;
    for (int i = 0; i < n - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < n; j++) { 
            if (arr[min_index] > arr[j]) min_index = j;
        }
        int t = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = t;
    }
}

int countOccurrences(int* arr, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) count++;
    }
    return count;
}

void histogramPostotaka() {
    int n;
    scanf("%d", &n);

    int* arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSortHistogramPostotaka(arr, n);

    int total = n; 

    for (int i = 0; i < n; i++) { 
        int count = countOccurrences(arr, n, i); 
        if (count>0 || i<=arr[0])printf("%d: ", i);

        int percentage = round(((float)count / total) * 100); 
        for (int j = 0; j < percentage; j++) {
            printf("x");
        }
        printf("\n");
    }
}
