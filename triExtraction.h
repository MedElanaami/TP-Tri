//
// Created by med on 12/20/2023.
//

#ifndef TP_TRI_TRIEXTRACTION_H
#define TP_TRI_TRIEXTRACTION_H


#include "fonctions.h"
#include "initTab.h"
#include "Liste.h"

/***************Tab***************/
//Fonction tri par extraction tableau
void triExtraction(int *tab, int taille){
    //Affichage tableau avant tri
    printf("Tableau avant tri: \t\t\t");
    afficheTab(tab, taille);
    //Affichage tableau apres tri
    int i, j,iteration = 0;
    for(i = 0; i < taille; i++){
        int min = i;
        for(j = i + 1; j < taille; j++){
            if(tab[j] < tab[min]){
                min = j;
            }
        }
        iteration++;
        printf("\nIteration num %d : Echange %d et %d\t",
               iteration,
               tab[i], tab[min]);
        echange(&tab[i], &tab[min]);
        afficheTab(tab, taille);
    }
    //Affichage nombre d'iteration
    printf("\nNombre d'iteration: %d\n", iteration);

};
/***************Liste***************/
//Fonction tri par extraction Liste  chainee
void triExtractionListe(Cellule *liste){
    //Affichage liste avant tri
    printf("Liste avant tri: \t\t\t");
    afficheListe(liste);
    //Affichage liste apres tri
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
        iteration++;
        printf("\nIteration num %d : Echange %d et %d\t",
               iteration,
               temp->valeur, min->valeur);
        echange(&temp->valeur, &min->valeur);
        afficheListe(liste);
        temp = temp->suivant;
    }
    //Affichage nombre d'iteration
    printf("\nNombre d'iteration: %d\n", iteration);
};


//Fonction tri par extraction arbre binaire
//Structure arbre binaire
typedef struct Noeud{
    int valeur;
    struct Noeud *gauche;
    struct Noeud *droit;
}Noeud;

// Function to display the binary search tree level by level
void afficheArbreBinaireNiveau(Noeud *arbre, int niveau) {
    if (arbre == NULL)
        return;

    if (niveau == 1)
        printf("%d ", arbre->valeur);
    else if (niveau > 1) {
        afficheArbreBinaireNiveau(arbre->gauche, niveau - 1);
        afficheArbreBinaireNiveau(arbre->droit, niveau - 1);
    }
}

// Function to get the height of the binary search tree
int hauteurArbreBinaire(Noeud *arbre) {
    if (arbre == NULL)
        return 0;
    else {
        int hauteurGauche = hauteurArbreBinaire(arbre->gauche);
        int hauteurDroit = hauteurArbreBinaire(arbre->droit);

        return (hauteurGauche > hauteurDroit) ? (hauteurGauche + 1) : (hauteurDroit + 1);
    }
}

// Function to display the binary search tree
void afficheArbreBinaire(Noeud *arbre) {
    int hauteur = hauteurArbreBinaire(arbre);
    for (int i = 1; i <= hauteur; i++) {
        afficheArbreBinaireNiveau(arbre, i);
    }
}
//Fonction d'insertion dans un arbre binaire
Noeud *insertionArbreBinaire(Noeud *arbre, int valeur){
    if(arbre == NULL){
        Noeud *nouveau = malloc(sizeof(Noeud));
        nouveau->valeur = valeur;
        nouveau->gauche = NULL;
        nouveau->droit = NULL;
        return nouveau;
    }
    if(valeur < arbre->valeur){
        arbre->gauche = insertionArbreBinaire(arbre->gauche, valeur);
    }else{
        arbre->droit = insertionArbreBinaire(arbre->droit, valeur);
    }
    return arbre;
}

Noeud *descend(Noeud *arbre)
{
    if ( (arbre->gauche) && (arbre->valeur > arbre->gauche->valeur)  )
        echange(&arbre->valeur,&arbre->valeur);
    if ( (arbre->droit) && (arbre->valeur > arbre->droit->valeur)  )
        echange(    &arbre->valeur,  &arbre->valeur);
    return((Noeud*)arbre);
}
Noeud *Construire (Noeud *arbre)
{
    if (arbre)
    {
        arbre->gauche= Construire(arbre->gauche);
        arbre=descend(arbre);
        arbre->droit= Construire(arbre->droit);
    }
    return ((Noeud*)arbre);
}


//Fonction de recherche d'un Noeud dans un arbre binaire
Noeud *rechercheArbreBinaire(Noeud *arbre, int valeur){
    if(arbre == NULL){
        return NULL;
    }
    if(arbre->valeur == valeur){
        return arbre;
    }
    if(valeur < arbre->valeur){
        return rechercheArbreBinaire(arbre->gauche, valeur);
    }else{
        return rechercheArbreBinaire(arbre->droit, valeur);
    }
}

//Fonction de suppression d'un Noeud dans un arbre binaire
Noeud *suppressionArbreBinaire(Noeud *arbre, int valeur){
    if(arbre == NULL){
        return NULL;
    }
    if(arbre->valeur == valeur){
        if(arbre->gauche == NULL && arbre->droit == NULL){
            free(arbre);
            return NULL;
        }
        if(arbre->gauche == NULL){
            Noeud *temp = arbre->droit;
            free(arbre);
            return temp;
        }
        if(arbre->droit == NULL){
            Noeud *temp = arbre->gauche;
            free(arbre);
            return temp;
        }
        Noeud *temp = arbre->droit;
        while(temp->gauche != NULL){
            temp = temp->gauche;
        }
        arbre->valeur = temp->valeur;
        arbre->droit = suppressionArbreBinaire(arbre->droit, temp->valeur);
        return arbre;
    }
    if(valeur < arbre->valeur){
        arbre->gauche = suppressionArbreBinaire(arbre->gauche, valeur);
    }else{
        arbre->droit = suppressionArbreBinaire(arbre->droit, valeur);
    }
    return arbre;
}

// Function to perform in-order traversal and print the elements
void inOrderTraversal(Noeud *arbre) {
    if (arbre != NULL) {
        inOrderTraversal(arbre->gauche);
        printf("%d ", arbre->valeur);
        inOrderTraversal(arbre->droit);
    }
}

//Fonction tri par extraction arbre binaire

// Function for Binary Tree Sort
void triExtractionArbreBinaire(Noeud *arbre) {
    // Create an empty binary search tree
    Noeud *sortedTree = NULL;
    int iteration = 1;
    // Insert elements from the original tree into the new tree
    while (arbre != NULL) {
        sortedTree = insertionArbreBinaire(sortedTree, arbre->valeur);

        // Display the current state
        printf("\n\nArbre binaire apres %dme iteration: ", iteration);

       // printf("\nNombre d'iteration: %d\n", iteration);

        printf("\n\nIteration num %d\t\t\t",
               iteration);
        afficheArbreBinaire(sortedTree);
        arbre = suppressionArbreBinaire(arbre, arbre->valeur);
        iteration++;
    }

    // Perform in-order traversal to get the sorted order
    printf("\nArbre trie par extraction: ");
    afficheArbreBinaire(sortedTree);
    printf("\n");
}
//void triExtractionArbreBinaire(Noeud *arbre) {
//    // Create an empty binary search tree
//    Noeud *sortedTree = NULL;
//
//    // Insert elements from the original tree into the new tree
//    while (arbre != NULL) {
//        sortedTree = insertionArbreBinaire(sortedTree, arbre->valeur);
//        arbre = suppressionArbreBinaire(arbre, arbre->valeur);
//    }
//
//    // Perform in-order traversal to get the sorted order
//    printf("Sorted order after Binary Tree Sort: ");
//    inOrderTraversal(sortedTree);
//    printf("\n");
//}


#endif //TP_TRI_TRIEXTRACTION_H
