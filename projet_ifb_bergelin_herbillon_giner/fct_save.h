//
// Created by julie on 08/06/2021.
//

#ifndef PROJET_IFB_BERGELIN_HERBILLON_GINER_FCT_SAVE_H
#define PROJET_IFB_BERGELIN_HERBILLON_GINER_FCT_SAVE_H
#include "grid.h"
#include <stdio.h>
#include <string.h>
/**
* sauvegarde dans un fichier le numéro i pour svoir a qui est le tour, le nom des deux joueurs, la grille de jeu ainsi que sa taille
* @param Structure Grid (g1) avec la grille de jeu et sa taille
* @param le nombre i pour savoir qui va jouer quand on va reprendre la partie
* @param les deux noms des deux joueurs
* @return 0 si le programme a mal été sauvegardé et 1 si la sauvegarde a reussi
*/
int save(Grid g1,int i,char *joueur1,char *joueur2);

/**
* charge une partie sauvegardé ulterieurement en livant les données sur le fichier
* @param le fichier fptr pour pouvoir charger la partie
* @param Gructure Grid (g1) pour pouvoir reprendre la grille de jeu
* @param le nombre de colonne pour la taille du tableau
* @param le nom des joueurs 1 et  2
* @return le nombe i pour savoir a qui c'est de jouer ou 0 si le le fichier n'existe pas
*/
int load(FILE*fptr,Grid *g1,int colonne,char *joueur1,char *joueur2);
#endif //PROJET_IFB_BERGELIN_HERBILLON_GINER_FCT_SAVE_H
