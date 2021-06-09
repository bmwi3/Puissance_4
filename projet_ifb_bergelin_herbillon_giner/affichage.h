//
// Created by julie on 08/06/2021.
//

#ifndef PROJET_IFB_BERGELIN_HERBILLON_GINER_AFFICHAGE_H
#define PROJET_IFB_BERGELIN_HERBILLON_GINER_AFFICHAGE_H
#include "grid.h"
#include "fct_check.h"

/**
* Permet d'afficher le logo puissance N
*/
void logo(void);

/**
* permet de présenter et de récupérer les choix de l'utilisateur tour après tour
* @param Structure Grid (g1) avec la grille de jeu et sa taille
* @return choice pour être utilisé dans le switch du main qui permet de lancer les différentes fonctions.
*/
int option_choice(Grid g1);

#endif //PROJET_IFB_BERGELIN_HERBILLON_GINER_AFFICHAGE_H
