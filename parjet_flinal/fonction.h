#ifndef PROJET_BIS_FONCTION_H
#define PROJET_BIS_FONCTION_H
#pragma once
#include "grid.h"
#include "fonction_check.h"




void logo(void);
int IA (Grid g1,char jeton, char colonne);
int option_choice(Grid g1);
int add_token_bis(Grid g1,char jeton,int colonne);
int remove_token(Grid g1,char jeton, int colonne);




#endif //PROJET_BIS_FONCTION_H
