//
// Created by julie on 28/05/2021.
//
#include <stdio.h>
#include "fonction.h"
#include <stdlib.h>

void logo(void) {
    printf(" ____\n");
    printf("|    |                                                |       |\n");
    printf("|____|                                                | |     |\n");
    printf("|         .   ___    ___   ___    ___    ___   ___    |   |   |\n");
    printf("|  |   |  |  |___   |___  |___|  |   |  |     |___    |     | |\n");
    printf("|  |___|  |   ___|   ___| |   |  |   |  |___  |___    |       |\n");
};

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


int trouver_x (Grid g1, int colonne, char jeton ){
    int x = 0, y = colonne - 1;

    while (g1.grille[x][y]!='O' && g1.grille[x][y]!='X' && x<g1.largeur-1){
        x++;
    }
    return x;
}

int check_colonne (Grid g1, int colonne, char jeton, int x){
    int y = colonne - 1,j = 0,compteur_colonne = 1;
    int c = 1;

    do{
        j++;
        if (x+j > g1.largeur-1){

            c = 0;
            //printf("a,c,g\n");
        }else if (g1.grille[x + j][y] != jeton ){// on compare le dernier jeton jouer avec celui d'en dessous
            c = 0;
        }
        // printf("%d=g\n",c);
        compteur_colonne += c ;     // compteur de jeton aligner sur une colone
        //printf("colonne = %d\n\n",compteur_colonne);

    } while (c != 0 && compteur_colonne != g1.largeur-2);

    return compteur_colonne;
}

int check_ligne (Grid g1, int colonne, char jeton,int x){
    int y = colonne - 1,j = 0,compteur_ligne = 1;
    int ld = 1, lg = 1;

    do{
        j++;
        if (g1.largeur -1 < y +j){
            ld = 0;
        } else if (g1.grille[x][y+ j] != jeton ){ // on compare le dernier jeton jouer avec celui a sa droite
            ld = 0;
        }


        if ( y - j < 0){
            lg = 0;
        }else if (g1.grille[x][y- j] != jeton ){ // on compare le dernier jeton jouer avec celui a sa gauche
            lg = 0;
        }

        compteur_ligne += ld + lg ;

    } while (ld + lg != 0 && compteur_ligne != g1.largeur-2);

    return compteur_ligne;
}

int check_diagonaled (Grid g1, int colonne, char jeton, int x){
    int y = colonne - 1,j = 0,compteur_diagonaled = 1;
    int bd = 1, hg = 1;

    do {
        j++;
        if (x+j > g1.largeur-1){
            bd = 0;
        }else if (g1.largeur -1 < y +j ){
            bd = 0;
        }else if (g1.grille[ j+ x ][y + j] != jeton ){  // on compare le dernier jeton jouer avec celui en bas a droite
            bd = 0;
        }

        if (x - j<0){
            hg = 0;
        } else if ( y - j < 0) {
            hg = 0;
        }else if (g1.grille[x- j][y- j] != jeton ){  // on compare le dernier jeton jouer avec celui en haut a gauche
            hg = 0;
        }

        compteur_diagonaled += hg + bd; // compteur de jeton aligner dans la premiere diagonale


    }while(hg + bd != 0&& compteur_diagonaled!= g1.largeur-2);
    return compteur_diagonaled;
}

int check_diagonaleg (Grid g1, int colonne, char jeton, int x){
    int y = colonne - 1,j = 0,compteur_diagonaleg = 1;
    int bg = 1, hd = 1;
    do {
        j++;
        if (x+j > g1.largeur-1){
            bg = 0;
        }else if ( y - j < 0) {
            bg = 0;
        }else  if (g1.grille[x+ j][y- j] != jeton ){ // on compare le dernier jeton jouer avec celui en bas a gauche
            bg = 0;
        }


        if (x - j<0){
            hd = 0;
        }else if (g1.largeur -1 < y +j ){
            hd = 0;
        }else if (g1.grille[x- j][y+ j] != jeton ){ // on compare le dernier jeton jouer avec celui en haut a droite
            hd = 0;
        }

        compteur_diagonaleg += hd + bg; // compteur de jeton aligner dans la premiere diagonale


    }while(hd + bg != 0 && compteur_diagonaleg != g1.largeur-2);
    return compteur_diagonaleg;
}

int  check_winner(Grid g1, int colonne,char jeton) {
    int x  = trouver_x ( g1, colonne, jeton );



    if (check_ligne (g1,colonne,jeton,x) == g1.largeur - 2 ||  check_colonne (g1, colonne, jeton, x) == g1.largeur - 2 || check_diagonaled (g1, colonne, jeton, x) == g1.largeur - 2 || check_diagonaleg (g1, colonne, jeton, x) == g1.largeur - 2) {
        if (jeton == 'O') {
            printf("joueur 1 gagne bravo vous avez gagner\n");
            return 0;
        } else {
            printf("joueur 2 gagne bravo vous avez gagner\n");
            return 1;
        }
    }
    return -1;
}

int check_grille_pleine (Grid g1,int colonne,char jeton){
    int compteur_egalite = 0;
    int rejouer;
    int x = trouver_x ( g1, colonne, jeton );
    if (x==0) { //regarde si il y a egalite
        do {
            if (g1.grille[0][compteur_egalite] != ' ') {
                compteur_egalite++;
            }

        } while (g1.grille[0][compteur_egalite] != ' ');

        if (compteur_egalite == g1.largeur ) {
            printf("grille pleine voulait vous continué ?\n1 pour continuer\n2 pour quitter\n");
            do {
                scanf("%d", &rejouer);
                if (rejouer != 1 || rejouer != 2 ){

                    printf("Impossible, choisir 1 ou 2/n\n");
                }
            }while (rejouer != 1 && rejouer != 2 );
            if (rejouer == 1 ){
                return 1;
            }
        }
    }
    return -1;
}

int check_ligne_bas_pleine(Grid g1){

    int compteur_egalite=0;

    do {
        if (g1.grille[g1.largeur-1][compteur_egalite] == ' ') {
            compteur_egalite++;
        }

    } while (g1.grille[g1.largeur-1][compteur_egalite] == ' ');

    if (compteur_egalite == g1.largeur) {
        return 1;
    } else{
        return 0;
    }

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