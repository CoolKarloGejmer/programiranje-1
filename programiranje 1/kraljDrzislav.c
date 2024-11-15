#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int* decToBin8(int t, int* br) {
	for (int i = 7; i >= 0; i--) {
		if (t - (int)pow(2, i) >= 0) {
			br[7 - i] = 1;
			t -= (int)pow(2, i);
		}
		else br[7 - i] = 0;
	}

	return br;
}

int* decToBin16(int t, int* br) {
	for (int i = 15; i >= 0; i--) {
		if (t - (int)pow(2, i) >= 0) {
			br[15 - i] = 1;
			t -= (int)pow(2, i);
		}
		else br[15 - i] = 0;
	}

	return br;
}

void kraljDrzislav() {
	char znak[256];
	int b1[16], b2[16], n;
	int t[8];
	int br[32];
	unsigned int y=0;
	scanf("%d %d %d", &b1[0], &b2[0],&n);
	scanf("%s", &znak);

	//pretvorba b1 i b2 u binarno
	decToBin16(b1[0],b1);
	decToBin16(b2[0], b2);

	//svaki znak obradit i ispisat
	for (int x = 0; x < n; x++) {
		//spajanje tih brojeva u jedan 
		for (int i = 0; i < 16; i++) {
			br[i] = b1[i];
			br[i + 16] = b2[i];
		}

		decToBin8((int)znak[0], t);

		//pridruzivanje binarnog zapisa znaka u veliki broj
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0)br[i + 24] = t[i];
			else if (i % 2 != 0)br[i + 8] = t[i];
		}
		y = 0;
		//pretvaranje binarnog u decimalni
		for (int i = 0; i < 32; i++) {
			if (br[31 - i] == 1)y += pow(2, i);
		}
		printf("%u\n", y);
	}
}