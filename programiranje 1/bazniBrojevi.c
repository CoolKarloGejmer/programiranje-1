#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void bazni() {
	int jmbag[10] = { 0,2,4,6,7,8,4,2,3,4 };
	int oib[10] = { 4,8,7,1,7,7,9,9,9,7 };
	int j = 9, o = 9, carry = 0;
	int oktJmbag[10];
	int oktOib[10];
	int oktzbroj[10];

	//posto nema test caseova pretpostavit cemo da je unos tipa 0 0 1 3 4 1 0 9... za jmbag i za oib
	/*for (int x = 0; x < 2; x++) {
		for (int i = 0; i < 10; i++) {
			if (x == 0) {
				scanf("%d", &jmbag[i]);
			}
			else scanf("%d", &oib[i]);
		}
	}*/

	//prvi for loop je da prodjemo oib i jmbag bez da pisemo kod dvaput
	//obrnuti for loop je da ide unazad kako bi se vrijednosti mjesta ostavile
	//svaki broj koji je 0-7 se pomice desno koliko moze do slj "ispravnog" (broj koji je 0-7) broja
	//sve to spremamo u "oktalni" array tako da s lijeva imamo nedefinirane vrijednosti u listi a s desna brojeve koji su oktalnih vrijednosti (0-7)
	for (int x = 0; x < 2; x++) {
		for (int i = 9; i >= 0; i--) {
			if (x == 0 && jmbag[i] <= 7) {
				oktJmbag[j] = jmbag[i];
				j--;
			}
			else if (x == 1 && oib[i] <= 7) {
				oktOib[o] = oib[i];
				o--;
			}
		}
	}


	//zamjena nedefiniranih vrijednosti s nulom radi tocnog racunanja
	for (int i = 0; i < 10; i++) if (oktJmbag[i] < 0) oktJmbag[i] = 0;
	for (int i = 0; i < 10; i++) if (oktOib[i] < 0) oktOib[i] = 0;


	//Zbrajanje oktalno-isto kao na papiru kad bi iso zbrajat dva oktalna broja
	for (int i = 9; i >= 0; i--) {
		oktzbroj[i] = oktJmbag[i] + oktOib[i] + carry;
		if (oktzbroj[i] > 7) carry = 1;
		else carry = 0;
		oktzbroj[i] = oktzbroj[i] % 8;
	}

	//pretvorba u heksadekadski oblik
	//ic cemo oct>dec>hex

	//oct>dec
	int dec = 0;
	for (int i = 0; i < 10; i++) {
		dec += oktzbroj[i] * pow(8, (9 - i));
	}

	//dec>hex>char
	char fakehex[10];
	sprintf(fakehex, "%X", dec);
	char hex[10];
	sprintf(hex, "%s", fakehex);

	//pomicanje slove ulijevo
	char realhex[10];
	j = 9;
	for (int x = 0; x < 2; x++) {
		for (int i = 9; i >= 0; i--) {
			if (x == 0 && hex[i] == (int)hex[i]) {
				realhex[j] = hex[i];
				j--;
			}
			printf("%s\n", realhex);
		}
	}

	
	return 0;
}