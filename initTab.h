#ifndef TP_TRI_INITTAB_H
#define TP_TRI_INITTAB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Fonction initialisation tableau
void initTab(int *tab, int taille){
    int values[] = {9, 8, 7, 6, 8, 1, 3, 2, 1, 0};
    for (int i = 0; i < taille; i++) {
        tab[i] = values[i];
    }

}
#endif //TP_TRI_INITTAB_H
