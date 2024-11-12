#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

float dec2(float novac) {
	novac *= 100;
	novac = round(novac);
	novac = novac / 100;
	return novac;
}

void giza() { 
	int br,ke=0,count=0;
	float k[100], p[100], novac = 100.0, kmin = 99999999999999999, pmax = 0;
	scanf("%d", &br);
	for (int i = 0; i < br; i++) {
		scanf("%f %f", &k[i], &p[i]);

		if ( kmin > k[i]) kmin = k[i];
		if( pmax<p[i])	pmax = p[i];

		if (ke == 0 && kmin == k[i]) {
			novac = novac / k[i];
			novac = dec2(novac);
			count++;
			ke = 1;
			//printf("\n---%d %f %f \n\n", count, novac, k[i]);
		}
		else if (ke == 1 && pmax == p[i]) {
			novac *= p[i]; 
			novac = dec2(novac);
			count++;
			ke = 0;
			//printf("\n---%d %f %f \n\n", count, novac, p[i]);
		}
		//printf("\n-------------%f %f ------------\n", kmin, pmax);
	}
	if (ke==0)printf("Nakon %d promjena, ostaje mu %.2f kn.", count,novac);
	else printf("Nakon %d promjena, ostaje mu %.2f EUR.", count, novac);
}