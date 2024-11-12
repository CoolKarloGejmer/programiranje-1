#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void kalk() {
	char op;
	int br1,br2;
	scanf("%d%c", &br1, &op);
	if (op != 'K') {
		scanf("%d",&br2);
		
		switch (op) {
		case '+':
			printf("%d", br1 + br2);
		case '-':
			printf("%d", br1 - br2);
		case '*':
			printf("%d", br1 * br2);
		case '/':
			printf("%d", br1 / br2);
		}
		return;
	}
	else if(op == 'K') printf("%d", pow(br1, 2));
}