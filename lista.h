#ifndef LISTA_H
#define LISTA_H

#include "postac.h"

typedef struct Node{
    Postac dane;
    struct Node* next;
}Node;

Node* utworzListe();

void dodajPostac(Node** head, Postac nowaPostac);

// void usunPostac(Node** head, const char* pseudonim);

void wyswietl(Node* head);

// void wyszukajPoPseudonimie(Node* head, const char* pseudonim);

// void wyszukajPoZagrozeniu(Node* head, int zagrozenie);

// Node* sortujAlfabetycznie(Node* head);

// Node* sortujPoZagrozeniu(Node* head);

void zwolnijPamiec(Node** head);

#endif