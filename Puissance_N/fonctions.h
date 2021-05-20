//
// Created by julie on 05/05/2021.
//

#pragma once
#ifndef PUISSANCE_N_FONCTIONS_H
#define PUISSANCE_N_FONCTIONS_H


typedef struct{
    int hauteur;
    int largeur;
    char **grille;
}Grid;


void logo(void);
void vider_buffer(void);
void action ();
int add_token(char *grid, int indice_colonne, char *jeton,int colonne_max);
int remove_token(char *grid, int indice_colonne, char *jeton,int colonne_max);
void show_grid(Grid g1);
int remove_token_bis(char**grid, int colonne,int largeur);
int add_token_bis(char**grid,char jeton, int colonne,int largeur);

  

   

#endif //PUISSANCE_N_FONCTIONS_H
