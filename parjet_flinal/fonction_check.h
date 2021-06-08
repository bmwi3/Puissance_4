//
// Created by utilisateur on 04/06/2021.
//

#ifndef PROJET_BIS_FONCTION_CHECK_H
#define PROJET_BIS_FONCTION_CHECK_H
#include "grid.h"

int check_winner (Grid g1,int colonne, char jeton);
int check_colonne (Grid g1, int colonne, char jeton, int x);
int check_ligne (Grid g1, int colonne, char jeton,int x);
int check_diagonaled (Grid g1, int colonne, char jeton,int x);
int check_diagonaleg (Grid g1, int colonne, char jeton,int x);
int check_grille_pleine (Grid g1,int colonne, char jeton);
int check_ligne_bas_vide(Grid g1);
int trouver_x (Grid g1, int colonne, char jeton );

#endif //PROJET_BIS_FONCTION_CHECK_H

