#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* get_element(char* znak) {
    if (strcmp(znak, "Ovan") == 0 || strcmp(znak, "Lav") == 0 || strcmp(znak, "Strijelac") == 0) {
        return "Vatreni";
    }
    else if (strcmp(znak, "Bik") == 0 || strcmp(znak, "Djevica") == 0 || strcmp(znak, "Jarac") == 0) {
        return "Zemljani";
    }
    else if (strcmp(znak, "Blizanci") == 0 || strcmp(znak, "Vaga") == 0 || strcmp(znak, "Vodenjak") == 0) {
        return "Zracni";
    }
    else if (strcmp(znak, "Rak") == 0 || strcmp(znak, "Skorpion") == 0 || strcmp(znak, "Ribe") == 0) {
        return "Vodeni";
    }
}

char* get_znak(int d, int m) {
    static char znak[30];

    if (m == 1) {
        if (d < 21) strcpy(znak, "Jarac");
        else strcpy(znak, "Vodenjak");
    }
    else if (m == 2) {
        if (d < 19) strcpy(znak, "Vodenjak");
        else strcpy(znak, "Ribe");
    }
    else if (m == 3) {
        if (d < 21) strcpy(znak, "Ribe");
        else strcpy(znak, "Ovan");
    }
    else if (m == 4) {
        if (d < 21) strcpy(znak, "Ovan");
        else strcpy(znak, "Bik");
    }
    else if (m == 5) {
        if (d < 21) strcpy(znak, "Bik");
        else strcpy(znak, "Blizanci");
    }
    else if (m == 6) {
        if (d < 22) strcpy(znak, "Blizanci");
        else strcpy(znak, "Rak");
    }
    else if (m == 7) {
        if (d < 23) strcpy(znak, "Rak");
        else strcpy(znak, "Lav");
    }
    else if (m == 8) {
        if (d < 23) strcpy(znak, "Lav");
        else strcpy(znak, "Djevica");
    }
    else if (m == 9) {
        if (d < 23) strcpy(znak, "Djevica");
        else strcpy(znak, "Vaga");
    }
    else if (m == 10) {
        if (d < 23) strcpy(znak, "Vaga");
        else strcpy(znak, "Škorpion");
    }
    else if (m == 11) {
        if (d < 22) strcpy(znak, "Škorpion");
        else strcpy(znak, "Strijelac");
    }
    else if (m == 12) {
        if (d < 22) strcpy(znak, "Strijelac");
        else strcpy(znak, "Jarac");
    }

    return znak;
}

void zapetljaniZnakovi() {
    int d, m, g, br = 0;
    char* znak;
    char* element;

    scanf("%d.%d.%d..", &d, &m, &g);
    while (1) {
        if (d < 1 || d > 31) { printf("Krivi unos!\n"); scanf("%d", &d); }
        if (m > 12 || m < 1) { printf("Krivi unos!\n"); scanf("%d", &m); }
        if (g < 1900 || g > 2999) { printf("Krivi unos!\n"); scanf("%d", &g); }
        if (d >= 1 && d <= 31 && m <= 12 && m >= 1 && g <= 2999 && g >= 1900) break;
        while (getchar() != '\n');
    }

    znak = get_znak(d, m);
    element = get_element(znak);
    printf("%s\n%s znak\n", znak, element);

    scanf("%d", &br);
    for (int i = 0; i < br; i++) {
        scanf("%d.%d.%d..", &d, &m, &g);
        while (1) {
            if (d < 1 || d > 31) { printf("Krivi unos!\n"); scanf("%d", &d); }
            if (m > 12 || m < 1) { printf("Krivi unos!\n"); scanf("%d", &m); }
            if (g < 1900 || g > 2999) { printf("Krivi unos!\n"); scanf("%d",&g); }
            if (d>=1 && d<=31 && m<=12 && m>=1 && g<=2999 && g>=1900) break;
            while (getchar() != '\n');
        }
        printf("Sa znakom %d.%d.%d. %s ", d, m, g, get_znak(d, m));
        if (strcmp(get_element(get_znak(d, m)), element) != 0) {
            printf("ne ");
        }
        printf("slaze se najbolje.\n");
    }
}
