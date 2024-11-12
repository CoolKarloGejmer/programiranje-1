#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void proizvodnjaDijamanata() {
	int br,zag;
	scanf("%d", &br);
	if (br % 2 == 0) {
		printf("Pogreska: Zadani dijamant nije savrsen!");
		return;
	}

	for (int i = 1; i <= (br-1); i+=2) {
		for (int j = 0; j < (br-i)/2; j++) printf(" ");
		for (int j = 0; j < i; j++)printf("*");
		printf("\n");
	}
	for (int i = 0; i < br; i++) printf("*");
	printf("\n");
	for (int i = br-2; i >=1; i-=2) {
		for (int j = 0; j < (br-i)/2; j++) printf(" ");
		for (int j = 0; j < i; j++)printf("*");
		printf("\n");
	}
}