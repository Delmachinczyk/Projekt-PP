#ifndef POSTAC_H
#define POSTAC_H

#define MAX_PSEUDONIM 100
#define MAX_ROLA 20
#define MAX_MOC 200
#define MAX_DZIELNICA 50
#define MAX_STATUS 20

typedef struct{
    char pseudonim[MAX_PSEUDONIM];
    char rola[MAX_ROLA];
    char moc[MAX_MOC];
    int zagrozenie;
    char dzielnica[MAX_DZIELNICA];
    char status[MAX_STATUS];
}Postac;

#endif