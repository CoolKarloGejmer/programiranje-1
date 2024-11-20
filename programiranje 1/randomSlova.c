#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void randomSlova() {
	int r,n;
	char red[5];
	scanf("%d", &n);
	for (int x = 0; x < n; x++) {
		for (int i = 0; i < 5; i++) {
			r = rand()%25;
			red[i] = (char)r+65;
			r = rand() % 2;
			if (r % 2 == 0)red[i] = tolower(red[i]);
		}
		printf("%c %c %c %c %c\n", red[0], red[1], red[2], red[3], red[4]);
	}
}