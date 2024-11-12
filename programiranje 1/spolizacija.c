#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void spolizacija() {
	int spol[3],br,x=0;
	for (int i = 0; i < 13; i++) {
		scanf("%d",&br);
		if (i > 6 && i < 10) {
			spol[x] = br;
			x++;
		}
	}
	if (spol[0] == 3 && spol[1] == 3) {
		switch (spol[2]) {
		case 0:
			printf("Musko!");
			return;
		case 5:
			printf("Zensko!");
			return;
		}
		printf("Greska!");
	}
	else printf("Greska!");
}