
#ifndef TP_TRI_TRIRAPIDE_H
#define TP_TRI_TRIRAPIDE_H
#include "fonctions.h"
#include "liste.h"

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
    afficheTab(tab, 10);

};


//Tri rapide a l'aide de la fonction partition et liste chainee
//Fonction partition
// Cellule *partitionListe(Cellule *gauche ,Cellule *droit){
//     int pivot = droit->valeureur;
//     Cellule *i = gauche;
//     Cellule *j;
//     int iteration = 0;
//     for(j = gauche; j != droit; j = j->suivant){
//         if(j->valeureur <= pivot){
//             i = i->suivant;
//             echange(&i->valeureur, &j->valeureur);
//         }
//     }
//     echange(&i->suivant->valeureur, &droit->valeureur);
//     return i->suivant;

// };
// //fonction tri rapide
// void triRapideListe(Cellule *gauche, Cellule *droit){

//     if(gauche != droit && gauche != NULL && droit != NULL){
//         afficheListe(gauche);
//         Cellule *pivot = partitionListe(gauche, droit);
//         triRapideListe(gauche, pivot);
//         triRapideListe(pivot->suivant, droit);
//     }

// };

Cellule * valeur_Indice(Cellule *liste, int indice)
{
// Parcourt la liste jusqu'à atteindre l'indice spécifié ou la fin de la liste
    while(liste != NULL && indice != 0)
    {
        liste = liste->suivant;
        indice--;
    }
// Retourne un pointeur vers la Cellule à l'indice spécifié
    return ((Cellule*)liste);
}

int Trouver_pivot(Cellule *liste, int i, int j)
{ 
    //prendre le maximum et l'afficher
    if (valeur_Indice(liste, i)->valeur > valeur_Indice(liste, j)->valeur)
        return i;
    return j;
}
int partition_liste(Cellule *liste, int debut, int fin, int pivot)
{
    int gauche = debut, droite = fin;
    do { // Trouve l'élément de gauche plus grand que le pivot
        while (valeur_Indice(liste, gauche)->valeur < pivot) gauche++;
// Trouve l'élément de droite plus petit que le pivot
        while (valeur_Indice(liste, droite)->valeur > pivot) droite--;
// Échange les éléments si nécessaire
        if (gauche < droite)
        {
            echange(&valeur_Indice(liste, gauche)->valeur, &valeur_Indice
            (liste, droite)->valeur);
        }
// La boucle s'arrête lorsque gauche est devenu plus grand ou égal à droite
    } while (gauche < droite);
    return gauche;
}

Cellule * Tri_Rapide_ptr(Cellule * liste, int i, int j)
{ // Cas de base : la liste est vide ou la portion à trier a une taille de 1 ou moins
    if (!liste || i >= j)
    {
        return liste;
    }
    int pivot, position_pivot, k;
// Trouver l'indice du pivot dans la portion à trier
    position_pivot = Trouver_pivot(liste, i, i + 1);
// Obtenir la valeureur du pivot
    pivot = valeur_Indice(liste, position_pivot)->valeur;
// Partitionner la liste autour du pivot et obtenir la nouvelle position du pivot
    k = partition_liste(liste, i, j, pivot);

    printf("\n ");
    printf("---------------iteration  ----------\n");

    afficheListe(liste);
// Tri récursif des sous-listes à gauche et à droite du pivot
    liste = Tri_Rapide_ptr(liste, i, k - 1);
    liste = Tri_Rapide_ptr(liste, k + 1, j);
    return liste;
}
#endif //TP_TRI_TRIRAPIDE_H
