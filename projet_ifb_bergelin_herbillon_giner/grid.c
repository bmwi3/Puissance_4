//
// Created by julie on 08/06/2021.
//

#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

void initialise(Grid *g1){

    g1->grille = (char**) malloc(sizeof (char*) * g1->largeur); //on impémente une largeur a notre tableau de caractère g1
    for (int i=0;i<g1->largeur;i++){
        g1->grille[i]=(char*) malloc(sizeof (char) * g1->hauteur);  //de meme on lui implémente une hauteur
        for (int j=0;j<g1->hauteur;j++){
            g1->grille[i][j] = '_'; //pour toute valeur du tableau, on initialise a "_"
        }
    }
}

void show_grid(Grid g1){
    for(int k=0;k<g1.largeur;k++){  //on numérote les colonnes du tableau pour facilité la saisi a l'utilisateur
        printf(" %d ",k+1);

    }
    printf("\n");
    for (int i=0;i<g1.largeur;i++){
        for (int j=0;j<g1.hauteur;j++){
            printf("{%c}",g1.grille[i][j]);//on affiche pour chaque case du tableau le caractère qu'elle contiens
        }
        printf("\n");
    }
}