//
// Created by julie on 05/05/2021.
//

#pragma once
#ifndef PUISSANCE_N_FONCTIONS_H
#define PUISSANCE_N_FONCTIONS_H

typedef struct {
    char pseudo[30],jeton
}personne;

typedef struct{
    int hauteur;
    int largeur;
    char **grille;
}Grid;

void logo(void);
void show_grid(Grid g1);
int check_winner(Grid g1,int n);
int option_choice();
int add_token_bis(Grid g1,char jeton,int colonne,int *x);
int remove_token(Grid g1,char jeton, int colonne);

  

   

#endif //PUISSANCE_N_FONCTIONS_H
