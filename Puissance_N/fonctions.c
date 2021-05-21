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

void show_grid(Grid g1){
    for(int k=0;k<g1.largeur;k++){
        printf(" %d ",k+1);

    }
    printf("\n");
    for (int i=0;i<g1.largeur;i++){
        for (int j=0;j<g1.hauteur;j++){
            printf("|%c|",g1.grille[i][j]);

        }
        printf("\n");
    }
}



int  check_winner(Grid g1,int n,int x) {

    int i, j = 0, x, y;
    int compteur_ligne=1, compteur_colone=1;
    int compteur_diagonaled=1, compteur_diagonaleg=1;
    int compteur_egalite = 0;
    int a=1, b=1, c=1, d=1, e=1, f=1, g=1, h=1, l;


    do{

        j++;

        if (g1.grille[x+j][y+j]!=g1.grille[x][y]){  // on compare le dernier jeton jouer avec celui en bas a droite
            a = 0;

        }
        if (g1.grille[x-j][y-j] !=g1.grille[x][y]){  // on compare le dernier jeton jouer avec celui en haut a gauche
            b = 0;

        }
        if (g1.grille[x+j][y-j]!=g1.grille[x][y]){ // on compare le dernier jeton jouer avec celui en haut a droite
            c = 0;

        }
        if (g1.grille[x-j][y+j] !=g1.grille[x][y]){ // on compare le dernier jeton jouer avec celui en bas a gauche
            d = 0;

        }
        if (g1.grille[x][y-j] !=g1.grille[x][y]){ // on compare le dernier jeton jouer avec celui au dessus
            e = 0;

        }
        if (g1.grille[x][y+j] !=g1.grille[x][y]){ // on compare le dernier jeton jouer avec celui en dessous
            f = 0;

        }
        if (g1.grille[x+j][y] !=g1.grille[x][y]){// on compare le dernier jeton jouer avec celui a sa droite
            g = 0;

        }
        if (g1.grille[x-j][y] !=g1.grille[x][y]){ // on compare le dernier jeton jouer avec celui a sa gauche
            h = 0;

        }
        compteur_diagonaled += b + a; // compteur de jeton aligner dans la premiere diagonale
        compteur_diagonaleg += c + d; // compteur de jeton aligner dans la deuxieme diagonale
        compteur_ligne += g + h;      // compteur de jeton aligner sur une ligne
        compteur_colone += e + f;     // compteur de jeton aligner sur une colone


        l = a + b + c + d + e + f + g + h;

        if (compteur_ligne  || compteur_colone ||compteur_diagonaled || compteur_diagonaleg == n){
            l =0;
        }

    }while ( l != 0 );



    if (y==0) {
        do {
            if (g1.grille[compteur_egalite][0] != '_') {
                compteur_egalite++;
            }

        } while (g1.grille[compteur_egalite][0] != '_')
        if (compteur_egalite == n + 2) {
            printf("egalite");
            return 2;
        }  else if (compteur_ligne  || compteur_colone ||compteur_diagonaled || compteur_diagonaleg == n){
            printf("joeur %s gagne!\n",'g1.grille[x][y]');
            return 1;
        } else {
            return -1;
        }
    }
 
}

int option_choice(){
int choice=0;
do {
printf("Voulez vous :\n 1.Ajouter un jeton\n 2.Enlever un jeton\n 3.Sauvegarder et quitter\n");
scanf("%d",&choice);
} while(choice!=(1||2||3));
return choice;

}
int add_token_bis(Grid g1,char jeton, int colonne){
    int i = 0;
    if (colonne-1 < 0 || colonne-1 > g1.largeur) {     // si la bonne colonne n'appartient pas au tableau
        return 0;                               //
    }
    if (g1.grille[0][colonne-1] != ' ') {        // si la colonne est pleine, on ne fait rien on a rien fait (renvois 0)
        return 0;
    }
printf("Done\n");
    while ( (g1.grille[i][colonne-1] != 'O'&&'X') && i<g1.largeur-1 )	//tant que l'on n'a pas une case vide on descent
    {                                                   //penser que la condition ne fonctionne que si il y a une ligne pleine en dessous
        i++;
    }
    if (g1.grille[i][colonne-1] != 'O'&&'X'){
        g1.grille[i][colonne-1]=jeton;
    }
    else{g1.grille[i-1][colonne-1]=jeton;}			//on ajoute un pion a la case dessus

    return 1;
}
