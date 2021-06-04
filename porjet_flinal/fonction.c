//
// Created by julie on 28/05/2021.
//
#include <stdio.h>
#include "fonction.h"
#include <stdlib.h>

void logo(void) {
    printf(" ____\n");
    printf("|    |                                                |       |\n");
    printf("|____|                                                | \\     |\n");
    printf("|         .   ___    ___   ___    ___    ___   ___    |   \\   |\n");
    printf("|  |   |  |  |___   |___  |___|  |   |  |     |___    |     \\ |\n");
    printf("|  |___|  |   ___|   ___| |   |  |   |  |___  |___    |       |\n");

int option_choice(Grid g1){
    int choice=0;
    do {
        printf("Voulez vous :\n 1.Ajouter un jeton\n 2.Enlever un jeton\n 3.Sauvegarder et quitter\n");
        scanf("%d",&choice);
        if (choice==2){
            if (check_ligne_bas_pleine(g1)==1){
                choice = 0;
                printf("impossible d'enlever un jeton la grille est vide\n");
            }
        }
    } while(choice!=1 && choice!=2 && choice!=3);
    return choice;

}

int add_token_bis(Grid g1,char jeton, int colonne){
    int i = 0;  //variable pour la hauteur du dernier jeton posé
    if (colonne-1 < 0 || colonne-1 > g1.largeur) {     // si la bonne colonne n'appartient pas au tableau
        return 0;
    }
    if (g1.grille[0][colonne-1] != '_') {        // si la colonne est pleine, on ne fait rien on a rien fait (renvois 0)
        return 0;
    }
    i= trouver_x(g1,colonne,jeton);
    if (g1.grille[i][colonne-1] != 'O'&& g1.grille[i][colonne-1] != 'X'){
        g1.grille[i][colonne-1]=jeton;
    }
    else{g1.grille[i-1][colonne-1]=jeton;}			//on ajoute un pion a la case dessus
    return 1;
}
int remove_token(Grid g1,char jeton, int colonne){
    int i = 0;
    if (colonne-1 < 0 || colonne-1 > g1.largeur) {     // si la bonne colonne n'appartient pas au tableau
        return 0;                               //
    }
    if (g1.grille[0][colonne-1] != '_') {        // si la colonne est pleine, on ne fait rien on a rien fait (renvois 0)
        return 0;
    }

    while ( (g1.grille[i][colonne-1] != 'O'&& g1.grille[i][colonne-1] != 'X') && i<g1.largeur-1 )	//tant que l'on n'a pas une case vide on descent
    {                                                   //penser que la condition ne fonctionne que si il y a une ligne pleine en dessous
        i++;
    }
    if(g1.grille[i][colonne-1]==jeton){
        printf("Vous ne pouvez pas retirer votre propore jeton\n");
        return 0;
    }
    if(i==g1.largeur || g1.grille[i][colonne-1]=='_'){
        return 0;
    }
    if (g1.grille[i][colonne-1] != '_'&& g1.grille[i][colonne-1] != jeton){
        g1.grille[i][colonne-1]='_';
    }

    return 1;
}


int IA (Grid g1,char jeton){
    int a, b;
    a = rand()%10 + 1;
    b = rand()%g1.largeur+1;

    if (check_ligne_bas_pleine(g1)== 1){
        a = 2;
    }

    if (a!=1){
        do {
            b++;
            if (b>g1.largeur){
                b=1;
            }
            printf("b = %d\n",b);

        } while (add_token_bis(g1,jeton, b) == 0);

    } else {
        do {
            b++;
            if (b>g1.largeur){
                b=1;
            }

        } while (remove_token(g1, jeton, b) == 0);
    }
    return b;
}
