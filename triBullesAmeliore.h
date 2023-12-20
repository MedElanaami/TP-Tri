//
// Created by med on 12/17/2023.
//

#ifndef TP_TRI_TRIBULLESAMELIORE_H
#define TP_TRI_TRIBULLESAMELIORE_H
#include "fonctions.h"

void triBulleAmeliorer(int *tab, int taille){
    //Affichage tableau avant tri
    printf("Tableau avant tri: \t\t\t");
    afficheTab(tab, taille);
    bool estTrie = false;
    int i, iteration = 0;
    while(!estTrie){
        estTrie = true;
        for(i = 0; i < taille - 1; i++){
            if(tab[i] > tab[i + 1]){
                iteration++;
                printf("\nIteration num %d : Echange %d et %d\t",
                       iteration,
                       tab[i], tab[i + 1]);
                echange(&tab[i], &tab[i + 1]);
                afficheTab(tab, taille);
                estTrie = false;
            }
        }
    }
    //Affichage nombre d'iteration
    printf("\nNombre d'iteration: %d\n", iteration);
};

#endif //TP_TRI_TRIBULLESAMELIORE_H
