//
// Created by julie on 08/06/2021.
//

#ifndef PROJET_IFB_BERGELIN_HERBILLON_GINER_MECANISME_JEU_H
#define PROJET_IFB_BERGELIN_HERBILLON_GINER_MECANISME_JEU_H
#include "grid.h"

/**
* joue automatiquement tour après tour soit en posant ou en reitrant un jeton
* @param Structure Grid (g1) avec la grille de jeu et sa taille
* @param le caractère jeton pour que l'ia place et retire le bon jeton
* @return b pour pouvoir controler si il y a un vainqueur grâce à la fonction check_winner
*/
int IA (Grid g1,char jeton);

/**
* permet d'ajouter un jeton dans la colonne choisit
* @param Structure Grid (g1) avec la grille de jeu et sa taille
* @param le caractère jeton pour placer le bon jeton 
* @param l'entier colonne pour savoir dans quelle colonne placer le jeton
* @return 0 si la colonne choisie ne remplit pas les conditions et return 1 si tout c'est bien passé
*/
int add_token_bis(Grid g1,char jeton,int colonne);

/**
* permet de retirer un jeton dans la colonne choisit
* @param Structure Grid (g1) avec la grille de jeu et sa taille
* @param le caractère jeton pour retirer le bon jeton
* @param l'entier colonne pour savoir dans quelle colonne retirer le jeton
* @return 0 si la colonne choisie ne remplit pas les conditions et return 1 si tout c'est bien passé
*/
int remove_token(Grid g1,char jeton, int colonne);
#endif //PROJET_IFB_BERGELIN_HERBILLON_GINER_MECANISME_JEU_H
