#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BETWEEN(br1, min, max) (br1>min && br1<max)

int upis(char p, int min,int max) {
	int x;
	while (1) {
		scanf("%d",&x);
		if (BETWEEN(x, min, max))break;
		printf("Neispravni unos parametra %c.\n",p);
		while (getchar() != '\n'); //u slucaju upisa slova clear buffer
	}
	return x;
}

int Xd(int x) {
	int count = 0;
	//krece od 2 jer se ne ubrajaju 1 i x
	for (int i = 2; i < x; i++) {
		if (x%i==0)count++;
	}
	return count;
}

int zbrznam(int x) {
	char znam[4]; //3 za troznamenkasti broj + 1 za null 
	int zbr = 0;
	sprintf(znam, "%d", x);
	for (int i = 0; i < strlen(znam); i++)zbr+=(int)znam[i]-'0';//-'0' jer su ascii vrijednosti
	return zbr;
}

void main() {
	int n, k, a;
	int count = 0;
	int sz=0,xd=0;
	int carape[100];

	//ovaj zadatak moguce je rjesit bez koristenja polja ali posto je vjezba napravljena da se koristi polje iskorist cemo ga
	//bez polja bi samo printali svaki put kad nadjemo odgovarajucu carapu u prvom for loopu

	n = upis('N', 5, 101);
	k = upis('K', 1, n + 1);
	a = upis('A', 0, n + 1);

	for (int i = a; i <= n; i++) {
		xd = Xd(i);
		if (sz + xd <= i) {
			carape[count] = i;
			sz += zbrznam(i);
			count++;
		}
		if (count == k)break;
	}
	printf("Uzet ce carape broj %d",carape[0]);
	for (int i = 1; i < count; i++)if (carape[i] > 1)printf(", %d", carape[i]);
	printf(".");
}