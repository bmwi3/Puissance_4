//
// Created by julie on 05/05/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"
void logo(void) {
    printf(" ____                                                  _______\n");
    printf("|    |                                                |       |            \n");
    printf("|____|                                                |       |                          \n");
    printf("|         .   ___    ___   ___    ___    ___   ___    |       |                 \n");
    printf("|  |   |  |  |___   |___  |___|  |   |  |     |___    |       |              \n");
    printf("|  |___|  |   ___|   ___| |   |  |   |  |___  |___    |       |                                             \n");
};

void vider_buffer(void) //permet de videer le buffer
{
    int c;

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void action (){ // fonction qui permet de proposer les differentes actions possible au joueur
    int c=0;

    printf("Voulez-vous:\n1.Ajouter un jeton\n2.Enlever un jeton\n3.Quitter\n");
    scanf("%d",&c);
    do {
        switch (c) {
            case 1:
                //appel de fonction add_token
                printf("appel de fonction add_token\n");
                break;
            case 2:
                //appel de fonction remove_token
                printf("appel de fonction remove_token");
                break;
            case 3:
                break;
            default:
                ;
        }
    } while (c!=1 && c!=2 && c!=3);

}

int add_token(char *grid, int indice_colonne, char *jeton){//verification colonne, verif jeton, modif colon return
    if (indice_colonne<0 || indice_colonne> colonnemax || grid[indice_colonne-1][0]!=' '){
        return 0;
    } else{
        if (jeton=='O'){
            grid[indice_colonne-1][0]='O';
            return 1;
        }
        else if (jeton=='X'){
            grid[indice_colonne-1][0]='X';
            return 1;
        }
    }

}


void show_grid(char grille,int largeur, int hauteur){
    for (int i=0 ; i<largeur ; i++){
        for (int j=0 ; j<hauteur ; j++){
            printf("{%c}\n", grille[i][j]);
        }
    }
}//fonction show grid a changer car le printf ne renvoie pas sur forme d'un tableau
