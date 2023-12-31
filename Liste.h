#ifndef TP_TRI_LISTE_H
#define TP_TRI_LISTE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Structure liste chainee
typedef struct Liste {
    int valeur;
    struct Liste *suivant;
}Cellule;

//Cree Cellule
Cellule *CreeCellule(int val){
    Cellule *cellule = malloc(sizeof(Cellule));
    if(cellule == NULL){
        printf("Erreur d'allocation memoire\n");
        exit(1);
    }
    cellule->valeur = val;
    cellule->suivant = NULL;
    return cellule;
}

//Fonction affichage liste chainee
void afficheListe(Cellule *liste){
    Cellule *temp = liste;
    while(temp != NULL){
        printf(" %d |", temp->valeur);
        temp = temp->suivant;
    }
    printf("\n");
}

//Fonction insertion en tete
Cellule *insertionEnTete(Cellule *liste, int val){
    Cellule *cellule = CreeCellule(val);
    cellule->suivant = liste;
    return cellule;
}

//Fonction insertion en queue
Cellule *insertionEnQueue(Cellule *liste, int val){
    Cellule *cellule = CreeCellule(val);
    if(liste == NULL){
        return cellule;
    }
    Cellule *temp = liste;
    while(temp->suivant != NULL){
        temp = temp->suivant;
    }
    temp->suivant = cellule;
    return liste;
}


//Initialisation liste chainee
Cellule *initialisationListe(Cellule *liste,int taille){

    for(int i = 0; i < taille; i++){
        liste = insertionEnTete(liste,  i);
    }
    return liste;
}

Cellule * videListe(Cellule *liste){
    liste = NULL;
    return liste;
}

#endif //TP_TRI_LISTE_H
