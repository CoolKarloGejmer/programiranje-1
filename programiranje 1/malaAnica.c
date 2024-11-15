#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void malaAnica() {
	int k, x, y,count=0;
	unsigned int n;
	unsigned int br[99999];

	scanf("%d %d", &n, &k);
	scanf("%d %d", &x, &y);

	for (int i = 2; i <= n; i+=2) {
		br[count] = k * i;
		count++;
	}
	for (int i = 0; i < x; i++)printf("%d\n", br[i]);
	for (int i = count-y-1; i >= x; i--)printf("%d\n", br[i]);
	for (int i = count-y; i < count; i++)printf("%d\n", br[i]);
}