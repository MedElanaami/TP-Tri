//
// Created by med on 12/17/2023.
//

#ifndef TP_TRI_TRIINSERTION_H
#define TP_TRI_TRIINSERTION_H
#include "fonctions.h"

//Fonction tri par insertion
void triInsertion(int *tab, int taille) {
    //Affichage tableau avant tri
    printf("Tableau avant tri: \t\t\t");
    afficheTab(tab, taille);

    int min = tab[0];
    int i, j, iteration = 0;
    for (i = 1; i < taille; i++) {
        j = i;
        while (j > 0 && tab[j] < tab[j - 1]) {
            iteration++;
            printf("\nIteration num %d : Echange %d et %d\t",
                   iteration,
                   tab[j], tab[j - 1]);
            echange(&tab[j], &tab[j - 1]);
            afficheTab(tab, taille);
            j--;
        }
    }
    //Affichage nombre d'iteration
    printf("\nNombre d'iteration: %d\n", iteration);
};


//Fonction tri par insertion Liste chainee
void triInsertionListe(Cellule *liste) {
    //Affichage liste avant tri
    printf("Liste avant tri: \t\t\t");
    afficheListe(liste);

    int min = liste->valeur;
    int iteration = 0;
    Cellule *temp = liste;
    while (temp != NULL) {
        Cellule *temp2 = temp->suivant;
        while (temp2 != NULL) {
            if (temp->valeur > temp2->valeur) {
                iteration++;
                printf("\nIteration num %d : Echange %d et %d\t",
                       iteration,
                       temp->valeur, temp2->valeur);
                echange(&temp->valeur, &temp2->valeur);
                afficheListe(liste);
            }
            temp2 = temp2->suivant;
        }
        temp = temp->suivant;
    }
    //Affichage nombre d'iteration
    printf("\nNombre d'iteration: %d\n", iteration);
};

#endif //TP_TRI_TRIINSERTION_H
