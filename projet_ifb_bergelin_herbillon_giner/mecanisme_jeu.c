//
// Created by julie on 08/06/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include "mecanisme_jeu.h"
#include "fct_check.h"

int add_token_bis(Grid g1, char jeton, int colonne) {
      //variable pour la hauteur du dernier jeton posé
    if (colonne - 1 < 0 || colonne - 1 > g1.largeur) {     // si la bonne colonne n'appartient pas au tableau
        return 0;
    }
    if (g1.grille[0][colonne - 1] != '_') {        // si la colonne est pleine, on ne fait rien on a rien fait (renvoie 0)
        return 0;
    }
    int i = trouver_x(g1, colonne);
    if (g1.grille[i][colonne - 1] != 'O' &&
        g1.grille[i][colonne - 1] != 'X') { //si la case est vide on y ajoute le jeton
        g1.grille[i][colonne - 1] = jeton; //la grille prend le jeton
    } else { g1.grille[i - 1][colonne - 1] = jeton; }            //on ajoute un pion a la case dessus
    return 1;
}
int remove_token(Grid g1, char jeton, int colonne) {//fonction qui enlève un jeton

    if (colonne - 1 < 0 || colonne - 1 > g1.largeur) {     // si la bonne colonne n'appartient pas au tableau
        return 0;                               //on retourne 0
    }

    int i = trouver_x(g1, colonne);
    if (g1.grille[i][colonne - 1] == jeton) {//si la case contient le même jeton que celui du joueur impossible de le retirer
        printf("Vous ne pouvez pas retirer votre propre jeton\n"); //message d'erreur
        return 0;
    }
    if (i == g1.largeur || g1.grille[i][colonne - 1] == '_') {//on verifie si la grille est vide
        return 0;
    }
    if (g1.grille[i][colonne - 1] != '_' &&
        g1.grille[i][colonne - 1] != jeton) {//si la case est remplie du jeton adverse
        g1.grille[i][colonne - 1] = '_';//on remplace le jeton adverse par le vide.
    }

    return 1;//retourne 1 si la fonction c'est bien passée
}



int IA(Grid g1, char jeton, char colonne){        //fonction basée sur l'aléa qui permet de jouer en 1vs ordi
    int a, b;           //le a permet de savoir si on ajoute ou enleve le jeton
    a = rand() % 10 + 1;          // a et b s'initialisent aléatoirement
    b = rand() % g1.largeur + 1;

    if (check_ligne_bas_vide(g1) == 1) {      //on vérifie si la ligne est vide
        a = 3;
    } else if (check_grille_pleine(g1, colonne) == 1) {  //on vérifie si la grille est pleine
        a = 1;
    }

    if (a != 1 && a != 2) { // si a est différent de 1 et 2
        do {        //on ajoute un jeton aléatoire tant que la fonction add-token n'autorise pas
            b++;
            if (b > g1.largeur) {
                b = 1;
            }
        } while (add_token_bis(g1, jeton, b) == 0);

    } else {
        do {        //on retire un jeton aléatoire tant que la fonction add-token n'autorise pas
            b++;
            if (b > g1.largeur) {
                b = 1;
            }

        } while (remove_token(g1, jeton, b) == 0);
    }
    return b;
}