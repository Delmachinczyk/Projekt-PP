#include <stdio.h>
#include <string.h>
#include "lista.h"
int main() {
    Node* head = NULL;
    int opcja;

    do{
       printf("\n=====Baza Bohaterow=====\n");
       printf("1- Dodawanie postaci\n");
       printf("2- Wyswietlanie obecnych postaci\n");
       printf("3- Usuwanie psotaci");
       printf("0- Zakonczenie programu\n");
       printf("Wybierz opcje: ");
       scanf("%d",&opcja);
       getchar();
       
    }while(opcja != 0);

    return 0;
}
