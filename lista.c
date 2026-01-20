#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Node* utworzListe(){
    return NULL;
}
void dodajPostac(Node** head, Postac nowaPostac){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Blad alokacji pamieci\n");
        return;
    }
    newNode->dane = nowaPostac;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }else{
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void wyswietl(Node* head){
    if(!head){
        printf("Lista jest pusta\n");
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        printf("Pseudonim: %s | Rola: %s | Moc: %s | Poziom zagrozenia: %d | Dzielnica: %s | Status: %s\n",
            temp->dane.pseudonim,
            temp->dane.rola,
            temp->dane.moc,
            temp->dane.zagrozenie,
            temp->dane.dzielnica,
            temp->dane.status);
            temp = temp->next;
    }
}

void zwolnijPamiec(Node** head){
    Node* temp;
    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}