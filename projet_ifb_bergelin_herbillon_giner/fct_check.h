//
// Created by julie on 08/06/2021.
//

#ifndef PROJET_IFB_BERGELIN_HERBILLON_GINER_FCT_CHECK_H
#define PROJET_IFB_BERGELIN_HERBILLON_GINER_FCT_CHECK_H
#include "grid.h"

int  check_winner(Grid g1, int colonne,char jeton,char *joueur1, char *joueur2);
int check_colonne (Grid g1, int colonne, char jeton, int x);
int check_ligne (Grid g1, int colonne, char jeton,int x);
int check_diagonaled (Grid g1, int colonne, char jeton,int x);
int check_diagonaleg (Grid g1, int colonne, char jeton,int x);
int check_grille_pleine (Grid g1,int colonne);
int check_ligne_bas_vide(Grid g1);
int trouver_x (Grid g1, int colonne);
int check_egalite (Grid g1,int colonne);
#endif //PROJET_IFB_BERGELIN_HERBILLON_GINER_FCT_CHECK_H
