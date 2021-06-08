//
// Created by julie on 28/05/2021.
//
#include <stdio.h>
#include "fonction.h"
#include <stdlib.h>


void logo(void) {                       //affiche notre "logo"
    printf(" ____\n");
    printf("|    |                                                |       |\n");
    printf("|____|                                                | \\     |\n");
    printf("|         .   ___    ___   ___    ___    ___   ___    |   \\   |\n");
    printf("|  |   |  |  |___   |___  |___|  |   |  |     |___    |     \\ |\n");
    printf("|  |___|  |   ___|   ___| |   |  |   |  |___  |___    |       |\n");
}

int option_choice(Grid g1) {
        int choice = 0;
        do {        //tant que l'utilisateur ne rentre pas un nombre autorise on présente les choix
            printf("Voulez vous :\n 1.Ajouter un jeton\n 2.Enlever un jeton\n 3.Sauvegarder et quitter\n");
            scanf("%d", &choice);
            if (choice == 2) {     //si on choisit de retirer un jeton on vérifie que la grille ne soit pas vide
                if (check_ligne_bas_vide(g1) == 1) {//si la grille est vide on ne peux pas retirer de jeton
                    choice = 0;     //choix prend 0 pour ne pas remplir les conditions de passage
                    printf("impossible d'enlever un jeton la grille est vide\n");
                }
            }
        } while (choice != 1 && choice != 2 && choice != 3);
        return choice;                  //on retourne la valeur de choice pour le switch dans le main

    }
int add_token_bis(Grid g1, char jeton, int colonne) {
    int i = 0;  //variable pour la hauteur du dernier jeton posé
    if (colonne - 1 < 0 || colonne - 1 > g1.largeur) {     // si la bonne colonne n'appartient pas au tableau
        return 0;
    }
    if (g1.grille[0][colonne - 1] != '_') {        // si la colonne est pleine, on ne fait rien on a rien fait (renvoie 0)
        return 0;
    }
        i = trouver_x(g1, colonne, jeton);
        if (g1.grille[i][colonne - 1] != 'O' &&
            g1.grille[i][colonne - 1] != 'X') { //si la case est vide on y ajoute le jeton
            g1.grille[i][colonne - 1] = jeton; //la grille prend le jeton
        } else { g1.grille[i - 1][colonne - 1] = jeton; }            //on ajoute un pion a la case dessus
        return 1;
    }
int remove_token(Grid g1, char jeton, int colonne) {//fonction qui enlève un jeton
        int i = 0;
        if (colonne - 1 < 0 || colonne - 1 > g1.largeur) {     // si la bonne colonne n'appartient pas au tableau
            return 0;                               //on retourne 0
        }
        if (g1.grille[0][colonne - 1] !=
            '_') {        // si la colonne est pleine, on ne fait rien on a rien fait (renvois 0)
            return 0;
        }

        while ((g1.grille[i][colonne - 1] != 'O' && g1.grille[i][colonne - 1] != 'X') &&
               i < g1.largeur - 1)    //tant que l'on n'a pas une case vide on descent
        {                                                   //penser que la condition ne fonctionne que si il y a une ligne pleine en dessous
            i++;
        }
        if (g1.grille[i][colonne - 1] ==
            jeton) {//si la case contient le même jeton que celui du joueur impossible de le retirer
            printf("Vous ne pouvez pas retirer votre propore jeton\n"); //message d'erreur
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

        if (check_ligne_bas_vide(g1) == 1) {      //on vérifie si la ligne est pleine
            a = 3;
        } else if (check_grille_pleine(g1, colonne, jeton) == 1) {  //on vérifie si la grille est pleine
                a = 1;
        }

        if (a != 1 && a != 2) { // si a est différent de 1
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
