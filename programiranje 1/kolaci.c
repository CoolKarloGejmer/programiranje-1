#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void kolaci() {
	float dz, brstr, dstr, visk, cijena,ispl;
	scanf("%f", &dz);

	scanf("%f", &brstr);
	while (brstr < 3) {
		printf("Krivi unos! Molim probajte opet.\n");
		scanf("%f", &brstr);
	}

	scanf("%f", &dstr);
	while (dstr < 0) {
		printf("Krivi unos! Molim probajte opet.\n");
		scanf("%f", &dstr);
	}

	scanf("%f", &visk);

	scanf("%f", &cijena);

	float v, h=visk, n=brstr, a=dstr;
	v = h * n * pow(a, 2) * (cos(3.14 / n) / sin(3.14 / n)) / 4;
	ispl = cijena / v;

	printf("Perica moze kupiti: %d kolaca, a platit ce %.2fkn/cm^3.",(int)(dz/cijena),ispl);
}