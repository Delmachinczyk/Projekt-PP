#include "pomocnicze.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void czyszczenieBufora(void){
    int dane;
    while((dane = getchar()) != '\n' && dane != EOF);
}

void wczytajTekst(char* tekst, int max_dlugosc){
    if(fgets(tekst, max_dlugosc, stdin) != NULL){
        size_t dlugosc_tekstu = strlen(tekst);
        if (dlugosc_tekstu > 0 && tekst[dlugosc_tekstu - 1] == '\n') {
            tekst[dlugosc_tekstu - 1] = '\0';
        }else{
            czyszczenieBufora();
        }
    }
}

int wczytajLiczbe(void){
    int x;
    while(scanf("%d", &x) != 1){
        printf("Podaj liczbe calkowita: \n");
        czyszczenieBufora();
    }
    czyszczenieBufora();
    return x;
}
int walidacjaZagrozenia(int zagrozenie){
    while(zagrozenie < 0 || zagrozenie > 10){
        printf("Podaj poziom zagrozenia (0-10): \n");
        zagrozenie = wczytajLiczbe();
    }
    return zagrozenie;
}