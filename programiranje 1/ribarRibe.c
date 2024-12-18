#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int simuliraj(char niz[], int n, int x) {
	int zbr = 0;
	//int count = 1; //pametne ribe

	for (int i = x; i < n; i++) {
		//if (niz[i] == 'T')zbr += 80; //za kapitalac
		/*if (niz[i] == 'A' || niz[i] == 'E' || niz[i] == 'I' || niz[i] == 'O' || niz[i] == 'U') { // za sklizave ribe
			zbr += niz[i] - 'A' + 1;
			i += 4;
			continue;
		}*/

		if (niz[i] != '.') {
			/*if (count % 3 == 0) { //pametne ribe
				continue;
			}
			count++;*/
			zbr += niz[i] - 'A' + 1;
			i += 2;
		}
	}

	return zbr;
}

void ribarRibe() {
	int n;
	char niz[MAX];
	//int opt[MAX]; //lista za analizu dok program radi
	int max[2] = {0,0};

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &niz[i]);
	}

	for (int i = 0; i < n; i++) {
		int zbr=simuliraj(niz, n, i);
		//opt[i] = zbr;
		//opt[i + n] = i;
		if (max[0] < zbr) { 
			max[0] = zbr; 
			max[1] = i;
		}
	}

	//for (int i = 0; i < n; i++)printf("x,zbr: %d  %d\n", opt[i + n], opt[i]);

	printf("Optimalno je baciti udicu nakon %ds, sto donosi %dkg ribe.", max[1]*10, max[0]);
}