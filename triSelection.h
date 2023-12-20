//
// Created by med on 12/17/2023.
//

#ifndef TP_TRI_TRISELECTION_H
#define TP_TRI_TRISELECTION_H

#include "fonctions.h"

//Fonction tri par selection
void triSelection(int *tab, int taille){
    //Affichage tableau avant tri
    printf("Tableau avant tri: \t\t\t");
    afficheTab(tab, taille);

    int i, j, min, iteration = 0;
    for(i = 0; i < taille - 1; i++){
        min = i;
        for(j = i + 1; j < taille; j++){
            if(tab[j] < tab[min]){
                min = j;
            }
        }
        if(min != i){
            iteration++;
            printf("\nIteration num %d : Echange %d et %d\t",
                   iteration,
                   tab[i], tab[min]);
            echange(&tab[i], &tab[min]);
            afficheTab(tab, taille);
        }
    }
    //Affichage nombre d'iteration
    printf("\nNombre d'iteration: %d\n", iteration);
};


//Fonction tri par selection Liste chainee
void triSelectionListe(Cellule *liste){
    //Affichage liste avant tri
    printf("Liste avant tri: \t\t\t");
    afficheListe(liste);

    int iteration = 0;
    Cellule *temp = liste;
    while(temp != NULL){
        Cellule *temp2 = temp->suivant;
        Cellule *min = temp;
        while(temp2 != NULL){
            if(temp2->valeur < min->valeur){
                min = temp2;
            }
            temp2 = temp2->suivant;
        }
        if(min != temp){
            iteration++;
            printf("\nIteration num %d : Echange %d et %d\t",
                   iteration,
                   temp->valeur, min->valeur);
            echange(&temp->valeur, &min->valeur);
            afficheListe(liste);
        }
        temp = temp->suivant;
    }
    //Affichage nombre d'iteration
    printf("\nNombre d'iteration: %d\n", iteration);
};


#endif //TP_TRI_TRISELECTION_H
