#include "fonction_check.h"
#include <stdio.h>


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
            
        }else if (g1.grille[x + j][y] != jeton ){// on compare le dernier jeton jouer avec celui d'en dessous
            c = 0;
        }
       
        compteur_colonne += c ;     // compteur de jeton aligner sur une colone
        

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
                    printf(" ___     ___     ____                _____\n");
            printf("|   \\   |   \\   |    |   \\      /   |     |     |\n");
            printf("|___/   |___/   |----|    \\    /    |     |     |\n");
            printf("|   \\   | \\     |    |     \\  /     |     |     |\n");
            printf("|___/   |  \\    |    |      \\/      |_____|     o\n");
        if (jeton == 'O') {
            printf("joueur 1 gagne!!\n");
            return 0;
        } else {
            printf("joueur 2 gagne!!\n");
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
