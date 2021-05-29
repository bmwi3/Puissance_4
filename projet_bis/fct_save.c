//
// Created by julien on 29/05/2021.
//

#include "fct_save.h"
#include <stdio.h>
#include "fonction.h"
#include <string.h>



int save(FILE*fptr, Grid g1,int i) {
    char array[( g1.largeur - 1)];
    fptr = fopen("save.txt", "wb");
    if (fptr == NULL) {
        printf(" File named save.txt does not exist or cannot be opened.\n");
        return 0;
    } else {
        /* for (int i = 0; i < g1.largeur; i++) {
             fprintf(fptr, "%s\n", g1.grille[i][0]);
         }*/
        fprintf(fptr, "%d %d",i,g1.hauteur);
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

int load(FILE*fptr,Grid g1){
fptr=fopen("save.txt","r");
int colonne=0, joueur=0;
    if(fptr==NULL) {
        printf(" File named save.txt does not exist or cannot be opened.\n");
        return 0;
    } /*else
    {
        char line[1024];

        fgets(line, 1024, fptr); // Reading first line of the file aka the next player
        sscanf(line, "Next player :   \t%d", k);

        fgets(line, 1024, fptr); // Reading second line of the file aka the number of columns and lines (they are equal since the board is a saquare)
        sscanf(line, "Tokens to align :\t%d", n);

        fgets(line, 1024, fptr); // Gets "GameBoard" but dumps it as it is not necessary in load function.

        initialise(g1);
        for (int i = 0; i < *n + 2; i++)
        {
            fgets(line, 1024, fptr); //Gets the line of characers corresponding to the line of the grid
            for (int j = 0; j < *n + 2; j++)
            {
                g1->grille[i][j] = line[j]; //Gets the individual character for the specified coordinates in the grid and stores it
                if (g1->grille[i][j] == 'X' || g1->grille[i][j] == 'O')
                {
                    g1->largeur++;
                }
            }
        }
        return *k - 1; //Returns the next player to play (0 for player 1 and 1 for player 2 according to the directives)
    }
}*/

    else {
        fscanf(fptr,"%d %d",&joueur,&colonne);//return column number and the turn

        initialise(&g1);
        g1.largeur=colonne;
        for (int j = 0; j < g1.largeur; j++){
            for (int k = 0; k < g1.largeur; k++){
                fscanf(fptr,"%c", g1.grille[j][k]);


            }
        }
        fclose(fptr);
        //printf("%d %d",joueur,colonne);
        show_grid(g1);


    }




}
