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

/*int add_token(char *grid, int indice_colonne, char *jeton, int colonne_max){//verification colonne, verif jeton, modif colon return
    if (indice_colonne<0 || indice_colonne> colonne_max || grid[indice_colonne-1][0]!=' '){
        return 0;
        printf("Impossible dans cette colonne!\n");
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

int remove_token(char *grid, int indice_colonne, char *jeton, int colonne_max){//verification colonne, verif jeton, modif colon return
    if (indice_colonne<0 || indice_colonne> colonne_max || grid[indice_colonne-1][0]!=' '){
        return 0;
        printf("Impossible dans cette colonne!\n");
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

}*/
int add_token_bis(char**grid,char jeton, int colonne,int largeur) {
    int i = 0;
    if (colonne < 0 || colonne > largeur) {     // si la bonne colonne n'appartient pas au tableau
        return 0;                               //
    }
    if (grid[0][colonne] != ' ') {        // si la colonne est pleine, on ne fait rien on a rien fait (renvois 0)
        return 0;
    }

    while ( grid[i][colonne] == ' ' && (i<largeur) )	//tant que l'on n'a pas une case vide on descent
    {                                                   //penser que la condition ne fonctionne que si il y a une ligne pleine en dessous
        i++;
    }

    grid[i-1][colonne]=jeton;			//on ajoute un pion a la case dessus

    return 1;
}

int remove_token_bis(char**grid, int colonne,int largeur) {
    int i = 0;
    if (colonne < 0 || colonne > largeur) {     // si la bonne colonne n'appartient pas au tableau
        return 0;                               //
    }
    if (grid[0][colonne] != ' ') {        // si la colonne est pleine, on ne fait rien on a rien fait (renvois 0)
        return 0;
    }

    while ( grid[i][colonne] == ' ' && (i<largeur) )	//tant que l'on n'a pas une case vide on descent
    {                                                   //penser que la condition ne fonctionne que si il y a une ligne pleine en dessous
        i++;
    }

    grid[i][colonne]=' ';			//on ajoute un pion a la case dessus

    return 1;
}


void show_grid(char** grille,int largeur, int hauteur){
    for (int i=0;i<largeur;i++){
        for (int j=0;j<hauteur;j++){
            printf("|%c|",grille[i][j]);

        }
        printf("\n");
    }
}

int check_winner(char **grid, int n) {

    int i, j = 0, h, n, x, y, nb1_ligne=0, nb2_ligne=0, nb3_ligne=0, nb1_colone=0, nb2_colone=0, nb3_colone=0;
    int nb_diagonaled=grid[x][y], nb_diagonaleg=0;
    int a=1, b=1, c=1, d=1 , e=0;

    for (i = 0; i = n-1; i++){

        nb1_ligne += grid[i][y];
        nb2_ligne += grid[i+1][y];
        nb3_ligne += grid[i+2][y];
        nb1_colone += grid[x][i];
        nb2_colone += grid[x][i+1];
        nb3_colone += grid[x][i+2];

    }
    do{

        j++;

        if (grid[x+j][y+j]!=grid[x][y]){
            a = 0;

        }
        if (grid[x-j][d-j] !=grid[x][y]){
            b = 0;

        }
        if (grid[x+j][y-j]!=grid[x][y]){
            c = 0;

        }
        if (grid[x+j][d-j] !=grid[x][y]){
            d = 0;

        }
        nb_diagonaled += b*grid[x-j][d-j] + a*grid[x+j][y+j];
        nb_diagonaleg += c*grid[x+j][d-j] + d*grid[x+j][y-j];
        e = a + b + c + d;

    }while ( e != 0 );

    if ((nb2_ligne || nb3_ligne ||nb1_ligne) == n * grid[x][y]) {
        printf("joueur %c gagne", grid[x][y]);
        return 1;

    } else if ((nb1_colone || nb2_colone ||nb3_colone) == n * grid[x][y]) {
        printf("joueur %c gagne", grid[x][y]);
        return 1;

    }else if(nb_diagonaled == n * grid[x][y]){
        printf("joueur %c gagne", grid[x][y]);
        return 1;
    }else if(nb_diagonaled == n * grid[x][y]){
        printf("joueur %c gagne", grid[x][y]);
        return 1;
    }else{
        return 0;
    }


}
