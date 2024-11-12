#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void nakvadrat() {
	int br,count=0;
	float rez;
	scanf("%d", &br);
	for (int i = 2; i < br; i++) {
		rez = (float)br / pow(i, 2);
		if (rez == (int)rez) count++;
	}
	printf("%d", count);
}