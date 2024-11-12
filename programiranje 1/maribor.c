#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void maribor() {
	int D, M, G=0, H, m, s;
	int sek;
	while (G > 2015 || G < 1900) {
		scanf("%d %d %d %d %d %d ", &D, &M, &G, &H, &m, &s);
	}
	scanf("%d", &sek);

	s += s + sek % 60;

	if (s / 60 > 0) {
		m += s / 60;
		s %= 60;
	}

	m += sek % 60;
	sek /= 60;

	if (m / 60 > 0) {
		H += m / 60;
		m %= 60;
	}

	H += sek % 24;
	sek /= 24;

	if (H / 24 > 0) {
		D += H / 24;
		H %= 24;
	}

	int danMj,danG;

	switch (M) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		danMj = 31;
		break;

	case 6:
	case 9:
	case 4:
	case 11:
		danMj = 30;
		break;

	case 2:
		if (G % 100 == 0 && G % 400 == 0 || G%4==0) {
			danG = 366;
			danMj = 29;
		}
		else {
			danG = 365;
			danMj = 28;
		}

	}

	D += sek;
	if (D / danMj > 0) {
		M += D / danMj;
		D %= danG;
		D %= danMj;
	}

	if (M / 12 > 0) {
		G += M / 12;
		if (M % 12 == 0)M = 1;
		M %= 12;
	}

	printf("%d %d %d %d %d %d", D, M, G, H, m, s);
}