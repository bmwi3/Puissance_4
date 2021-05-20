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
/*int add_token_bis(char**grid,char jeton, int colonne,int largeur) {
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
}*/

/*int remove_token_bis(char**grid, int colonne,int largeur) {
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
*/

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


int check_winner(Grid g1,int n) {

    int i, j = 0, x, y, somme1_ligne=0, somme2_ligne=0, somme3_ligne=0, somme1_colone=0, somme2_colone=0, somme3_colone=0;
    int somme_diagonaled=g1.grille[x][y], somme_diagonaleg=g1.grille[x][y];
    int a=1, b=1, c=1, d=1 , e=0;

    for (i = 0; i = n-1; i++){

        somme1_ligne += g1.grille[i][y];
        somme2_ligne += g1.grille[i+1][y];
        somme3_ligne += g1.grille[i+2][y];
        somme1_colone += g1.grille[x][i];
        somme2_colone += g1.grille[x][i+1];
        somme3_colone += g1.grille[x][i+2];

    }
    do{

        j++;

        if (g1.grille[x+j][y+j]!=g1.grille[x][y]){
            a = 0;

        }
        if (g1.grille[x-j][d-j] !=g1.grille[x][y]){
            b = 0;

        }
        if (g1.grille[x+j][y-j]!=g1.grille[x][y]){
            c = 0;

        }
        if (g1.grille[x+j][d-j] !=g1.grille[x][y]){
            d = 0;

        }
        somme_diagonaled += b*g1.grille[x-j][d-j] + a*g1.grille[x+j][y+j];
        somme_diagonaleg += c*g1.grille[x+j][d-j] + d*g1.grille[x+j][y-j];
        e = a + b + c + d;

    }while ( e != 0 );

    if ((somme2_ligne || somme3_ligne ||somme1_ligne) == n * g1.grille[x][y]) {
        printf("joueur %c gagne", g1.grille[x][y]);
        return 1;

    } else if ((somme1_colone || somme2_colone ||somme3_colone) == n * g1.grille[x][y]) {
        printf("joueur %c gagne", g1.grille[x][y]);
        return 1;

    }else if(somme_diagonaled == n * g1.grille[x][y]){
        printf("joueur %c gagne", g1.grille[x][y]);
        return 1;
    }else if(somme_diagonaled == n * g1.grille[x][y]){
        printf("joueur %c gagne", g1.grille[x][y]);
        return 1;
    }else{
        return 0;
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
int add_token_bis(Grid g1,char jeton,int colonne) {

    int j=0;

    while (g1.grille[j][colonne-1]!=jeton && j<g1.largeur-1){
        j=j+1;
    }
    if (g1.grille[j][colonne-1]!=jeton){
        g1.grille[j][colonne-1]=jeton;
    }else{
        g1.grille[j-1][colonne-1]=jeton;
    }


    return 1;
}
