#ifndef TP_TRI_FONCTIONS_H
#define TP_TRI_FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Fonction Echange
void echange(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
};

//Fonction affichage tableau
void afficheTab(int *tab, int taille){
    int i;
    for(i = 0; i < taille; i++){
        printf(" %d |", tab[i]);
    }
    printf("\n");
};

#endif //TP_TRI_FONCTIONS_H
