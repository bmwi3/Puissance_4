//
// Created by julie on 29/05/2021.
//

#ifndef PROJET_BIS_GRID_H
#define PROJET_BIS_GRID_H
typedef struct{
    int hauteur;
    int largeur;
    char **grille;
}Grid;
void show_grid(Grid g1);
void initialise(Grid *g1);

#endif //PROJET_BIS_GRID_H
