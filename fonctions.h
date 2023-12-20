//
// Created by med on 12/17/2023.
//

#ifndef TP_TRI_FONCTIONS_H
#define TP_TRI_FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




//



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

//Fonction calculer nombre d'iteration
int nbIteration(int taille){
    int i, nbIteration = 0;
    for(i = 0; i < taille; i++){
        nbIteration += i;
    }
    return nbIteration;
};
#endif //TP_TRI_FONCTIONS_H
