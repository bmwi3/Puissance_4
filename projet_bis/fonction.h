//
// Created by julie on 28/05/2021.
//

#ifndef PROJET_BIS_FONCTION_H
#define PROJET_BIS_FONCTION_H
#pragma once
#include "grid.h"

typedef struct Personne{
    char pseudo[30],jeton;
} Personne;



void logo(void);

int check_winner(Grid g1,int colonne, char jeton);
int option_choice();
int add_token_bis(Grid g1,char jeton,int colonne);
int remove_token(Grid g1,char jeton, int colonne);
void IA (Grid g1,char jeton);


#endif //PROJET_BIS_FONCTION_H
