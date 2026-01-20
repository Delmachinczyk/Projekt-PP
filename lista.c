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

void usunPostac(Node** head, const char* pseudonim){
    if(!*head){
        printf("Lista jest pusta, brak postaci do usuniecia \n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    while(temp != NULL){
        if(strcmp(temp->dane.pseudonim, pseudonim) == 0){
            if(strcmp(temp->dane.status,"uwieziony") == 0){
                printf("Nie mozna usunac uwiezionej postaci\n");
                return;
            }
            if(prev==NULL){
                *head = temp->next;
            }else{
                prev->next = temp->next;
            }

            free(temp);
            printf("Postac '%s' zostala usunieta\n",pseudonim);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Brak postaci o nazwie '%s' \n",pseudonim);
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

void wyszukajPoPseudonimie(Node* head, const char* pseudonim){
    if(!head){
        printf("Lista jest pusta, brak postaci do wyszukania\n");
        return;
    }

    Node* temp = head;
    int znalezione = 0;

    while(temp!=NULL){
        if(strcmp(temp->dane.pseudonim, pseudonim)==0){
            printf("Pseudonim: %s | Rola: %s | Moc: %s | Poziom zagrozenia: %d | Dzielnica: %s | Status: %s\n",
            temp->dane.pseudonim,
            temp->dane.rola,
            temp->dane.moc,
            temp->dane.zagrozenie,
            temp->dane.dzielnica,
            temp->dane.status);
            znalezione++;
        }
        temp = temp->next;
    }
    if(!znalezione){
        printf("Nie znaleziono postaci o pseudonimie '%s'\n",pseudonim);
    }else{
        printf("Liczba znalezionych postaci: ",znalezione);
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