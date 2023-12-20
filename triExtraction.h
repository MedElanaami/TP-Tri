//
// Created by med on 12/20/2023.
//

#ifndef TP_TRI_TRIEXTRACTION_H
#define TP_TRI_TRIEXTRACTION_H


#include "fonctions.h"
#include "initTab.h"
#include "Liste.h"

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
typedef struct noeud{
    int valeur;
    struct noeud *gauche;
    struct noeud *droit;
}Noeud;

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

//Fonction d'affichage d'un arbre binaire
void afficheArbreBinaire(Noeud *arbre){
    if(arbre != NULL){
        afficheArbreBinaire(arbre->gauche);
        printf("%d ", arbre->valeur);
        afficheArbreBinaire(arbre->droit);
    }
}

//Fonction de recherche d'un noeud dans un arbre binaire
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

//Fonction de suppression d'un noeud dans un arbre binaire
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

//Fonction de tri par extraction arbre binaire
void triExtractionArbreBinaire(Cellule *liste){
    //Affichage liste avant tri
    printf("Liste avant tri: \t\t\t");
    afficheListe(liste);
    //Affichage liste apres tri
    int iteration = 0;
    Cellule *temp = liste;
    Noeud *arbre = NULL;
    while(temp != NULL){
        arbre = insertionArbreBinaire(arbre, temp->valeur);
        temp = temp->suivant;
    }
    while(arbre != NULL){
        Noeud *min = arbre;
        while(min->gauche != NULL){
            min = min->gauche;
        }
        iteration++;
        printf("\nIteration num %d : Echange %d et %d\t",
               iteration,
               arbre->valeur, min->valeur);
        echange(&arbre->valeur, &min->valeur);
        afficheListe(liste);
        arbre = suppressionArbreBinaire(arbre, min->valeur);
    }
    //Affichage nombre d'iteration
    printf("\nNombre d'iteration: %d\n", iteration);
};



#endif //TP_TRI_TRIEXTRACTION_H
