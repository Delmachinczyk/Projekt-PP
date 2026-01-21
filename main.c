#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "pomocnicze.h"
int main() {
    Node* head = NULL;
    int opcja;
    char pseudonim[MAX_PSEUDONIM];
    Postac p;
    do{
       printf("\n=====Baza Bohaterow=====\n");
       printf("1- Dodawanie postaci\n");
       printf("2- Wyswietlanie obecnych postaci\n");
       printf("3- Usuwanie postaci\n");
       printf("4- Wyszukaj po pseudonimie\n");
       printf("5- Wyszukaj po zagrozeniu(>= od wpisanego)\n");
       printf("6- Sortuj alfabetycznie\n");
       printf("7- Sortuj po zagrozeniu\n");
       printf("0- Zakonczenie programu\n");
       printf("Wybierz opcje ");
       opcja = wczytajLiczbe();

       switch(opcja){
            case 0:
                printf("Koniec programu\n");
                break;
            case 1:
                printf("Podaj pseudonim: \n");
                wczytajTekst(p.pseudonim, MAX_PSEUDONIM);

                printf("Podaj role: \n");
                wczytajTekst(p.rola, MAX_ROLA);

                printf("Podaj moc: \n");
                wczytajTekst(p.moc, MAX_MOC);

                printf("Podaj poziom zagrozenia: \n");
                p.zagrozenie = walidacjaZagrozenia(wczytajLiczbe());

                printf("Podaj dzielnice dzialania: \n");
                wczytajTekst(p.dzielnica, MAX_DZIELNICA);

                printf("Podaj status operacyjny: \n");
                wczytajTekst(p.status, MAX_STATUS);

                dodajPostac(&head, p);
                printf("Dodano postac\n");
                break;
            case 2:
                wyswietl(head);
                break;
            case 3: 
                printf("Podaj pseudonim postaci do usuniecia: \n");
                wczytajTekst(pseudonim, MAX_PSEUDONIM);
                usunPostac(&head, pseudonim);
                break;
            case 4: 
                printf("Podaj pseudonim postaci: \n");
                wczytajTekst(pseudonim, MAX_PSEUDONIM);
                wyszukajPoPseudonimie(head, pseudonim);
                break;
            case 5: 
                int z;
                printf("Podaj minimalny poziom zagrozenia: \n");
                z = walidacjaZagrozenia(wczytajLiczbe());
                wyszukajPoZagrozeniu(head, z);
                break;
       }
    }while(opcja != 0);
    
    zwolnijPamiec(&head);
    return 0;
}
