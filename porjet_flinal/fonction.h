//
// Created by julie on 28/05/2021.
//

#ifndef PROJET_BIS_FONCTION_H
#define PROJET_BIS_FONCTION_H
#pragma once
#include "grid.h"




int check_winner (Grid g1,int colonne, char jeton);
int check_colonne (Grid g1, int colonne, char jeton, int x);
int check_ligne (Grid g1, int colonne, char jeton,int x);
int check_diagonaled (Grid g1, int colonne, char jeton,int x);
int check_diagonaleg (Grid g1, int colonne, char jeton,int x);
int check_grille_pleine (Grid g1,int colonne, char jeton);
int check_ligne_bas_pleine(Grid g1);
int trouver_x (Grid g1, int colonne, char jeton );

void logo(void);
int IA (Grid g1,char jeton);
int option_choice(Grid g1);
int add_token_bis(Grid g1,char jeton,int colonne);
int remove_token(Grid g1,char jeton, int colonne);




#endif //PROJET_BIS_FONCTION_H