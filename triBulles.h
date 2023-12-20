
#ifndef TP_TRI_TRIBULLES_H
#define TP_TRI_TRIBULLES_H
#include "fonctions.h"
#include "initTab.h"
#include "Liste.h"
///Fonction tri a bulles tableau
/// \param tab
void triBulles(int *tab, int taille){
    //Affichage tableau avant tri
    printf("Tableau avant tri: \t\t\t");
    afficheTab(tab, taille);
    //Affichage tableau apres tri
    int i, j,iteration = 0;
    for(i = 0; i < taille; i++){
        for(j = 0; j < taille - 1; j++){
            if(tab[j] > tab[j + 1]){
                iteration++;
                printf("\nIteration num %d : Echange %d et %d\t",
                       iteration,
                       tab[j], tab[j + 1]);
                echange(&tab[j], &tab[j + 1]);
                afficheTab(tab, taille);
            }
        }
    }
    //Affichage nombre d'iteration
    printf("\nNombre d'iteration: %d\n", iteration);

};

///Fonction tri a bulles Liste  chainee
/// \param liste
void triBullesListe(Cellule *liste){
    //Affichage liste avant tri
    printf("Liste avant tri: \t\t\t");
    afficheListe(liste);
    //Affichage liste apres tri
    int iteration = 0;
    Cellule *temp = liste;
    while(temp != NULL){
        Cellule *temp2 = temp->suivant;
        while(temp2 != NULL){
            if(temp->valeur > temp2->valeur){
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



#endif //TP_TRI_TRIBULLES_H
