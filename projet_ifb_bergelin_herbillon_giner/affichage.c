//
// Created by julie on 08/06/2021.
//
#include "stdio.h"
#include "affichage.h"

void logo(void) {                       //affiche notre "logo"
    printf(" ____\n");
    printf("|    |                                                |       |\n");
    printf("|____|                                                | \\     |\n");
    printf("|         .   ___    ___   ___    ___    ___   ___    |   \\   |\n");
    printf("|  |   |  |  |___   |___  |___|  |   |  |     |___    |     \\ |\n");
    printf("|  |___|  |   ___|   ___| |   |  |   |  |___  |___    |       |\n");
}

int option_choice(Grid g1,int colonne) {
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
        if (choice == 1) {     //si on choisit de retirer un jeton on vérifie que la grille ne soit pas vide
            if (check_grille_pleine(g1,colonne) == 1) {//si la grille est vide on ne peux pas retirer de jeton
                choice = 0;     //choix prend 0 pour ne pas remplir les conditions de passage
                printf("impossible d'ajouter un jeton la grille est pleine\n");
            }
        }
    } while (choice != 1 && choice != 2 && choice != 3);
    return choice;                  //on retourne la valeur de choice pour le switch dans le main

}
