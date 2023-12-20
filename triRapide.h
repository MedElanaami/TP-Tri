
#ifndef TP_TRI_TRIRAPIDE_H
#define TP_TRI_TRIRAPIDE_H
#include "fonctions.h"

//Tri rapide a l'aide de la fonction partition et tableaux
//Fonction partition
int partition(int gauche ,int droit , int *tab){
    int pivot = tab[droit];
    int i = gauche - 1;
    int j;
    int iteration = 0;
    for(j = gauche; j < droit; j++){
        if(tab[j] <= pivot){
            i++;
            echange(&tab[i], &tab[j]);
        }
    }
    echange(&tab[i + 1], &tab[droit]);
    return i + 1;

};
//fonction tri rapide
void triRapide(int gauche, int droit , int *tab){

    if(gauche < droit){
        afficheTab(tab, 10);
        int pivot = partition(gauche, droit, tab);
        triRapide(gauche, pivot - 1, tab);
        triRapide(pivot + 1, droit, tab);
    }

};


//Tri rapide a l'aide de la fonction partition et liste chainee
//Fonction partition
Cellule *partitionListe(Cellule *gauche ,Cellule *droit){
    int pivot = droit->valeur;
    Cellule *i = gauche;
    Cellule *j;
    int iteration = 0;
    for(j = gauche; j != droit; j = j->suivant){
        if(j->valeur <= pivot){
            i = i->suivant;
            echange(&i->valeur, &j->valeur);
        }
    }
    echange(&i->suivant->valeur, &droit->valeur);
    return i->suivant;

};
//fonction tri rapide
void triRapideListe(Cellule *gauche, Cellule *droit){

    if(gauche != droit && gauche != NULL && droit != NULL){
        afficheListe(gauche);
        Cellule *pivot = partitionListe(gauche, droit);
        triRapideListe(gauche, pivot);
        triRapideListe(pivot->suivant, droit);
    }

};






#endif //TP_TRI_TRIRAPIDE_H
