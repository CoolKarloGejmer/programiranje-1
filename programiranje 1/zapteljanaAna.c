#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void zapetljanaAna() {
	int cm[2], kg[2], god[2];
	int n;
	int partner[3];
	int count = 0;

	while (1) {
		scanf("%d %d", &cm[0], &cm[1]);
		if (cm[1] - cm[0] <= 35) {
			if (cm[0] > 50 && cm[0] <= 250 && cm[1] <= 250 && cm[1] > 50) {
				break;
			}
		}
		printf("Nepravilni unos visine!\n");
	}
	while (1) {
		scanf("%d %d", &kg[0], &kg[1]);
		if (kg[1] - kg[0] > 5) {
			if (kg[0] >= 50 && kg[0] <= 100 && kg[1] <= 100 && kg[1] >= 50) {
				break;
			}
		}
		printf("Nepravilni unos tezine!\n");
	}
	while (1) {
		scanf("%d %d", &god[0], &god[1]);
		if (god[1] - god[0] == 5) {
			if (god[0] > 15 && god[0] < 100 && god[1] < 100 && god[1] > 15) {
				break;
			}
		}
		printf("Nepravilni unos godina!\n");
	}

	while (1) {
		scanf("%d",&n);
		if (n > 3 && n <= 20)break;
		printf("Nepravilni unos broja partnera!\n");
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &partner[0], &partner[1], &partner[2]);
		if (partner[0] >= cm[0] && partner[0] <= cm[1]) {
			if (partner[1] >= kg[0] && partner[1] <= kg[1]) {
				if (partner[2] >= god[0] && partner[2] <= god[1]) {
					count++;
				}
			}
		}
	}
	if (count > 1) {
		printf("Prolazi kriterije: %d osobe.", count);
	}
	else printf("Prolazi kriterije: %d osoba.", count);
}