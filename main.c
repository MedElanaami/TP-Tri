#include <stdio.h>
#include <time.h>
#include "triBulles.h"
#include "triBullesAmeliore.h"
#include "triSelection.h"
#include "triInsertion.h"
#include "triRapide.h"
#include "initTab.h"
#include "Liste.h"
#include "triExtraction.h"


#define taille 10
int main() {
    
    // Tableau a trier
    int tab[taille];
// ------------------------------------------------
    printf("------------------------------------------------\n");
//// tri a bulle

    //Initialisation tableau
    initTab(tab, taille);
    printf("\n \t\tTRI A BULLES \n");
    
    // Record the start time
    clock_t temps_depart = clock();
    //Tri a bulles
    triBulles(tab, taille);
    // Record the end time
    clock_t temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_a_Bulles = ((double) (temps_fin - temps_depart)) /
                               CLOCKS_PER_SEC;
    // Print the elapsed time
    printf("Temps d'executuon pour TRI A BULLES: %f seconds\n",
           tempsTri_a_Bulles);

// ------------------------------------------------
    printf("------------------------------------------------\n");
//// tri a bulle ameliore

    //Initialisation tableau
    initTab(tab, taille);
    printf("\n \t\tTRI A BULLES AMELIORE \n");

    // Record the start time
    temps_depart = clock();
    //Tri a bulles ameliore
    triBulleAmeliorer(tab, taille);
    // Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_a_Bulles_Ameliorer = ((double) (temps_fin - temps_depart)) /
                                         CLOCKS_PER_SEC;
    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI A BULLES AMELIORE: %f seconds\n",
           tempsTri_a_Bulles_Ameliorer);

// ------------------------------------------------
    printf("------------------------------------------------\n");
/// Tri par insertion

    //Initialisation tableau
    initTab(tab, taille);
    printf("\n \t\tTRI PAR INSERTION\n");

    // Record the start time
    temps_depart = clock();
    //Tri a insertion
    triInsertion(tab, taille);
    // Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_Par_Insertion = ((double) (temps_fin - temps_depart)) /
                                    CLOCKS_PER_SEC;
    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI PAR INSERTION: %f seconds\n",
           tempsTri_Par_Insertion);

// ------------------------------------------------
    printf("------------------------------------------------\n");
/// Tri par selection

    //Initialisation tableau
    initTab(tab, taille);
    printf("\n \t\tTRI PAR SELECTION\n");

    // Record the start time
    temps_depart = clock();
    //Tri a selection
    triSelection(tab, taille);
    // Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_Par_Selection = ((double) (temps_fin - temps_depart)) /
                                    CLOCKS_PER_SEC;
    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI PAR SELECTION: %f seconds\n",
           tempsTri_Par_Selection);

// ------------------------------------------------
    printf("------------------------------------------------\n");

/// Tri rapide

    //Initialisation tableau
    initTab(tab, taille);
    printf("\n \t\tTRI RAPIDE\n");

    // Record the start time
    temps_depart = clock();
    //Tri a rapide
    triRapide(0, 9, tab);
   //  Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_Rapide = ((double) (temps_fin - temps_depart)) /
                                    CLOCKS_PER_SEC;
    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI RAPIDE: %f seconds\n",
           tempsTri_Rapide);

// ------------------------------------------------
//Cree liste chainee
    Cellule *liste= NULL;
    printf("------------------------------------------------\n");
    ///Tri a bulle Liste chainee
    printf("\n \t\tTRI A BULLES LISTE CHAINEE\n");

    //Initialisation liste chainee
    liste =NULL;
    for(int i = 0; i < taille; i++){
        liste = insertionEnTete(liste,  i);
    }
    // Record the start time
    temps_depart = clock();
    //Tri a bulles liste chainee
    triBullesListe(liste);
    // Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_a_Bulles_Liste = ((double) (temps_fin - temps_depart)) /
                                     CLOCKS_PER_SEC;
    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI A BULLES LISTE CHAINEE: %f seconds\n",
           tempsTri_a_Bulles_Liste);

// ------------------------------------------------
    printf("------------------------------------------------\n");
   ///Tri par insertion Liste chainee
    printf("\n \t\tTRI PAR INSERTION LISTE CHAINEE\n");

//Initialisation liste chainee
    liste =NULL;
    for(int i = 0; i < taille; i++){
        liste = insertionEnTete(liste,  i);
    }
    // Record the start time
    temps_depart = clock();
    //Tri a insertion liste chainee
    triInsertionListe(liste);
    // Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_Par_Insertion_Liste = ((double) (temps_fin - temps_depart)) /
                                          CLOCKS_PER_SEC;
    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI PAR INSERTION LISTE CHAINEE: %f seconds\n",
           tempsTri_Par_Insertion_Liste);

// ------------------------------------------------
    printf("------------------------------------------------\n");
    ///Tri par selection Liste chainee
    printf("\n \t\tTRI PAR SELECTION LISTE CHAINEE\n");

    //Initialisation liste chainee
    liste =NULL;
    for(int i = 0; i < taille; i++){
        liste = insertionEnTete(liste,  i);
    }
    
    // Record the start time
    temps_depart = clock();
    //Tri a selection liste chainee
    triSelectionListe(liste);
    // Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_Par_Selection_Liste = ((double) (temps_fin - temps_depart)) /
                                          CLOCKS_PER_SEC;

    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI PAR SELECTION LISTE CHAINEE: %f seconds\n",
           tempsTri_Par_Selection_Liste);

// ------------------------------------------------
    printf("------------------------------------------------\n");
    ///Tri rapide Liste chainee
    printf("\n \t\tTRI RAPIDE LISTE CHAINEE\n");

    //Initialisation liste chainee
    liste =NULL;
    for(int i = 0; i < taille; i++){
        liste = insertionEnTete(liste,  i);
    }
    afficheListe(liste);

    // Record the start time
    temps_depart = clock();
    //Tri a rapide liste chainee
    Tri_Rapide_ptr(liste, 0, 9);
    // Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_Rapide_Liste = ((double) (temps_fin - temps_depart)) /
                                          CLOCKS_PER_SEC;
    afficheListe(liste);
    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI RAPIDE LISTE CHAINEE: %f seconds\n",
           tempsTri_Rapide_Liste);


// ------------------------------------------------
    printf("------------------------------------------------\n");
    ///Tri par extraction Liste chainee
    printf("\n \t\tTRI PAR EXTRACTION LISTE CHAINEE\n");

    //Initialisation liste chainee
    liste =NULL;
    for(int i = 0; i < taille; i++){
        liste = insertionEnTete(liste,  i);
    }
    afficheListe(liste);

    // Record the start time
    temps_depart = clock();
    //Tri a extraction liste chainee
    triExtractionListe(liste);
    // Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_Extraction_Liste = ((double) (temps_fin - temps_depart)) /
                                          CLOCKS_PER_SEC;
    afficheListe(liste);
    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI PAR EXTRACTION LISTE CHAINEE: %f seconds\n",
           tempsTri_Extraction_Liste);


// ------------------------------------------------
    printf("------------------------------------------------\n");
    ///Tri par extraction Arbre binaire
    printf("\n \t\tTRI PAR EXTRACTION ARBRE BINAIRE\n");

   //Inisialition arbre binaire

    Noeud *arbre = NULL;
    for(int i = 0; i < taille; i++){
        arbre = insertionArbreBinaire(arbre, i);
    }
    afficheArbreBinaire(arbre);
    // Record the start time
    temps_depart = clock();
    //Tri a extraction arbre binaire
    triExtractionArbreBinaire(arbre);
    // Record the end time
    temps_fin = clock();
    // Calculate the elapsed time in seconds
    double tempsTri_Extraction_Arbre_Binaire = ((double) (temps_fin - temps_depart)) /
                                          CLOCKS_PER_SEC;
    afficheArbreBinaire(arbre);
    // Print the elapsed time
    printf("\nTemps d'executuon pour TRI PAR EXTRACTION ARBRE BINAIRE: %f seconds\n",
           tempsTri_Extraction_Arbre_Binaire);

    return 0;
}
