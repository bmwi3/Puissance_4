//
// Created by julien on 29/05/2021.
//

#include "fct_save.h"
#include <stdio.h>
#include "fonction.h"
#include <string.h>



int save(FILE*fptr, Grid g1,int i,char *joueur1,char *joueur2) {
    char array[( g1.largeur - 1)];
    fptr = fopen("save.txt", "w");
    if (fptr == NULL) {
        printf(" File named save.txt does not exist or cannot be opened.\n");
        return 0;
    } else {

        fprintf(fptr, "%d %d\n",i,g1.hauteur);
        fprintf(fptr,"%s %s\n",joueur1,joueur2);
    }
    for (int i = 0; i < g1.largeur; i++)
    {
        strcpy(array, g1.grille[i]);

        fputs(array, fptr);
        fputs("\n", fptr);
    }
    fclose(fptr);
    return 1;
}


int load(FILE*fptr,Grid *g1,int *colonne,char *joueur1,char *joueur2){
    int i;
    fptr=fopen("save.txt","r");
    if(fptr==NULL) {
        printf(" File named save.txt does not exist or cannot be opened.\n");
        return 0;
    }
    else {
        fscanf(fptr,"%d %d\n",&i,colonne);//return column number and the turn
        fscanf(fptr,"%s %s\n",joueur1,joueur2);

        g1->hauteur=g1->largeur=*colonne;
        initialise(g1);
        for (int j = 0; j < g1->largeur; j++){
            for (int k = 0; k < g1->largeur; k++){
                fscanf(fptr,"%c",&g1->grille[j][k]);


            }
            fscanf(fptr,"\n");
        }
        fclose(fptr);
        show_grid(*g1);


    }
    return i;



}
