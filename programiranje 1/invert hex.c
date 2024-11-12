#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void inverthex() {
	int hex, brznam=3;
	char hexList[100];
	scanf("%d", &brznam);
	scanf("%s", &hexList);
	for (int i = 0; i < brznam; i++) {
		if (hexList[i] <= '9' && hexList[i] >= '0') printf("%X", 15-(hexList[i]-'0'));
		else if (hexList[i] >= 'A' && hexList[i] <= 'F') {
			hex = (hexList[i] - 'A' + 10);
			printf("%X", 15-hex);
		}
	}


}