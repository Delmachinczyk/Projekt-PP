#include <stdio.h>
#include "lista.h"
int main() {
    Node* head = NULL;

    Postac p1 = {
        "SolarMan",
        "bohater",
        "kontrola slonca",
        3,
        "Centrum",
        "aktywny"
    };

    Postac p2 = {
        "NightFang",
        "zloczynca",
        "niewidzialnosc",
        7,
        "Port",
        "uwieziony"
    };

    dodajPostac(&head, p1);
    dodajPostac(&head, p2);

    printf("=== LISTA POSTACI ===\n");
    wyswietl(head);

    zwolnijPamiec(&head);

    if (head == NULL) {
        printf("\nLista zostala poprawnie zwolniona.\n");
    }

    return 0;
}
