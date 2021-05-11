//
// Created by julie on 05/05/2021.
//

#pragma once
#ifndef PUISSANCE_N_FONCTIONS_H
#define PUISSANCE_N_FONCTIONS_H

void logo(void);
void vider_buffer(void);
void action ();
int add_token(char *grid, int indice_colonne, char *jeton);
void show_grid(char grille, int largeur, int hauteur);
int check_winner(char **grid, int n);
  

    


#endif //PUISSANCE_N_FONCTIONS_H
