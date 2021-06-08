#ifndef PROJET_BIS_GRID_H
#define PROJET_BIS_GRID_H
typedef struct{
    int hauteur;
    int largeur;
    char **grille;
}Grid;

/**
* affiche une grille avec les caractère qu'elle contiens
* @param structure Grid qui contiens une matrice carré ainsi que ses dimentions 
*/
void show_grid(Grid g1);

/**
* initialise toute les case d'une grille avec le caractere '_'
* @param structure Grid passé par adresse 
*/
void initialise(Grid *g1);

#endif //PROJET_BIS_GRID_H