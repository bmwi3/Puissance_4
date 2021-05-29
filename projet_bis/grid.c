//
// Created by julie on 29/05/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "fonction.h"
#include "fct_save.h"
#include "grid.h"
void initialise(Grid *g1){

    g1->grille = (char**) malloc(sizeof (char*) * g1->largeur);
    for (int i=0;i<g1->largeur;i++){
        g1->grille[i]=(char*) malloc(sizeof (char) * g1->hauteur);
        for (int j=0;j<g1->hauteur;j++){
            g1->grille[i][j] = ' ';
        }
    }
}

void show_grid(Grid g1){
    for(int k=0;k<g1.largeur;k++){
        printf(" %d ",k+1);

    }
    printf("\n");
    for (int i=0;i<g1.largeur;i++){
        for (int j=0;j<g1.hauteur;j++){
            printf("{%c}",g1.grille[i][j]);

        }
        printf("\n");
    }
}