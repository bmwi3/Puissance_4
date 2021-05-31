//
// Created by julie on 28/05/2021.
//
#include <stdio.h>
#include "fonction.h"
#include <string.h>

void logo(void) {
    printf(" ____                                                          \n");
    printf("|    |                                                |       |\n");
    printf("|____|                                                | |     |\n");
    printf("|         .   ___    ___   ___    ___    ___   ___    |   |   |\n");
    printf("|  |   |  |  |___   |___  |___|  |   |  |     |___    |     | |\n");
    printf("|  |___|  |   ___|   ___| |   |  |   |  |___  |___    |       |\n");
};





int  check_winner(Grid g1, int colonne,char jeton) {

    int j = 0, y = colonne - 1,x  = 0;
    int compteur_ligne=1, compteur_colonne=1;
    int compteur_diagonaled=1, compteur_diagonaleg=1;
    int compteur_egalite = 0;
    int a=1, b=1, c=1, d=1, e=1, f=1, g=1, l;

    while (g1.grille[x][y]!=jeton && x<g1.largeur-1){
        x++;
    }
    printf("x = %d\n",x);
    printf("y = %d\n",y);


    do{




        j++;

        if (x+j > g1.largeur-1){
            a = 0;
            c = 0;
            g = 0;
            printf("a,c,g\n");
        }
        if (x - j<0){
            b = 0;
            d = 0;
            printf("b,d,h\n");
        }
        if (g1.largeur -1 < y +j ){
            a = 0;
            d = 0;
            f = 0;
            printf("a,d,f\n");
        }
        if ( y - j < 0) {
            b = 0;
            c = 0;
            e = 0;
            printf("b,c,e\n");
        }



        if (g1.grille[ a * j+ x ][y + a *j] != jeton ){  // on compare le dernier jeton jouer avec celui en bas a droite
            a = 0;
        }
        printf("%d=a\n",a);

        if (g1.grille[x- b *j][y- b * j] != jeton ){  // on compare le dernier jeton jouer avec celui en haut a gauche
            b = 0;
        }
        printf("%d=b\n",b);

        if (g1.grille[x+ c * j][y- c * j] != jeton ){ // on compare le dernier jeton jouer avec celui en haut a droite
            c = 0;
        }
        printf("%d=c\n",c);

        if (g1.grille[x- d * j][y+d * j] != jeton ){ // on compare le dernier jeton jouer avec celui en bas a gauche
            d = 0;
        }
        printf("%d=d\n",d);

        if (g1.grille[x][y- e * j] != jeton ){ // on compare le dernier jeton jouer avec celui a sa gauche
            e = 0;
        }
        printf("%d=e\n",e);
        if (g1.grille[x][y+ f * j] != jeton ){ // on compare le dernier jeton jouer avec celui a sa droite
            f = 0;
        }
        printf("%d=f\n",f);

        if (g1.grille[x + j * g][y] != jeton ){// on compare le dernier jeton jouer avec celui au dessous
            g = 0;
        }
        printf("%d=g\n",g);



        compteur_diagonaled += b + a; // compteur de jeton aligner dans la premiere diagonale
        printf("diagonaled = %d\n",compteur_diagonaled);
        compteur_diagonaleg += c + d; // compteur de jeton aligner dans la deuxieme diagonale
        printf("diagonaleg = %d\n",compteur_diagonaleg);
        compteur_ligne += e + f ;      // compteur de jeton aligner sur une ligne
        printf("ligne = %d\n",compteur_ligne);
        compteur_colonne += g ;     // compteur de jeton aligner sur une colone
        printf("colonne = %d\n\n",compteur_colonne);


        if (compteur_ligne == g1.largeur - 2 ||  compteur_colonne == g1.largeur - 2 || compteur_diagonaled == g1.largeur - 2 || compteur_diagonaleg == g1.largeur - 2) {
            if (jeton == 'O') {
                printf("joueur 1 gagne bravo\n");
                return 0;
            } else {
                printf("joueur 2 gagne bravo\n");
                return 1;
            }
        }

        l = a + b + c + d + e + f + g ;


    }while ( l != 0 );
    printf("%d\n",jeton);



    if (x==0) { //regarde si il y a egalite

        do {
            if (g1.grille[compteur_egalite][0] != '_') {
                compteur_egalite++;
            }

        } while (g1.grille[compteur_egalite][0] != '_');

        if (compteur_egalite == g1.largeur -1) {
            printf("egalite\n");
            return 2;
        }
    }


    return -1;



}

int option_choice(){
    int choice=0;
    do {
        printf("Voulez vous :\n 1.Ajouter un jeton\n 2.Enlever un jeton\n 3.Sauvegarder et quitter\n");
        scanf("%d",&choice);
    } while(choice!=1 && choice!=2 && choice!=3);
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
    while ( (g1.grille[i][colonne-1] != 'O'&& g1.grille[i][colonne-1] != 'X') && i<g1.largeur-1 )	//tant que l'on n'a pas une case vide on descent
    {                                                   //penser que la condition ne fonctionne que si il y a une ligne pleine en dessous
        i++;
    }
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
    if (g1.grille[0][colonne-1] != ' ') {        // si la colonne est pleine, on ne fait rien on a rien fait (renvois 0)
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
    if(i==g1.largeur || g1.grille[i][colonne-1]==' '){
        printf("Il n'y a rien à retirer\n");
        return 0;
    }
    if (g1.grille[i][colonne-1] != ' '&& g1.grille[i][colonne-1] != jeton){
        g1.grille[i][colonne-1]=' ';
    }

    return 1;
}
void IA (Grid g1,char jeton){
    int a, b;
    a = rand()%10 + 1;
    b = rand()%g1.largeur+1;
    /*if (check_equality == 0){
      a = 1;
      }
    */
    printf("b1 = %d\n",b);
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

}
