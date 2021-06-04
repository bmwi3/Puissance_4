//
// Created by julien on 29/05/2021.
//
#include "fonction.h"
#include "grid.h"
#include <stdio.h>
#ifndef PROJET_BIS_FCT_SAVE_H
#define PROJET_BIS_FCT_SAVE_H



int save(Grid g1,int i,char *joueur1,char *joueur2);
int load(FILE*fptr,Grid *g1,int *colonne,char *joueur1,char *joueur2);
#endif //PROJET_BIS_FCT_SAVE_H