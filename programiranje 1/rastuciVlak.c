#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void selectionSorted(int x[1000],int n) {
	int indx;
	int t;
	for (int i = 0; i < n-1; i++) {
		indx = i;
		for (int j = i+1; j < n; j++) {
			if (x[indx] > x[j])indx = j;
		}
		t = x[i];
		x[i] = x[indx];
		x[indx] = t;
	}
}

void rastuciVlak() {
	int n,evili,countNaprijed=0,countNazad=0;
	int vlak[1000];
	int kopija[1000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &vlak[i]);
		kopija[i] = vlak[i];
	}

	for (int i = n; i < 1000; i++) {
		vlak[i] = 0;
		kopija[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		evili = n - i - 1;

		if (vlak[i] > vlak[i + 1]) {
			vlak[i] = 0;
			countNaprijed++;
		}
		if (kopija[evili] > kopija[evili - 1]) {
			kopija[i] = 0;
			countNazad++;
		}
	}

	if (countNaprijed == countNazad) {
		printf("Ostaje %d vagona: ", n - countNaprijed);
		for (int i = 0; i < n - countNaprijed; i++) printf("%d ", vlak[i]);
	}
	else printf("%d %d", countNaprijed, countNazad);

}