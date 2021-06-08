//
// Created by julie on 08/06/2021.
//

#ifndef PROJET_IFB_BERGELIN_HERBILLON_GINER_FCT_CHECK_H
#define PROJET_IFB_BERGELIN_HERBILLON_GINER_FCT_CHECK_H
#include "grid.h"

/**
* verifie si un des joueurs a gagné ou non
* @param structure Grid (g1) avec la grille de jeu et sa taille
* @param le numéro de la colonne
* @param le type de jeton qui a gagné
* @param les noms des deux joueurs
* @return 0 si le joueur un a gagné 1 si le joueur deux a gagné et -1 si il y a toujours égalité
*/
int  check_winner(Grid g1, int colonne,char jeton,char *joueur1, char *joueur2);

/**
* verifie si un joueur a alligné le bon nombre de jeton sur une colonne
* @param structure Grid (g1) avec la grille de jeu et sa taille
* @param le numéro de la colonne
* @param le type de jeton qui a gagné
* @param variable pour trouver une colonne avec des jetons
* @return le nombre de jetons alligné en colonne au maximum
*/
int check_colonne (Grid g1, int colonne, char jeton, int x);

/**
* verifie si un joueur a alligné le bon nombre de jeton sur une ligne
* @param structure Grid (g1) avec la grille de jeu et sa taille
* @param le numéro de la colonne
* @param le type de jeton qui a gagné
* @param variable pour trouver une colonne avec des jetons
* @return le nombre de jetons alligné en ligne au maximum
*/
int check_ligne (Grid g1, int colonne, char jeton,int x);

/**
* verifie si un joueur a alligné le bon nombre de jeton sur une diagonale droite
* @param structure Grid (g1) avec la grille de jeu et sa taille
* @param le numéro de la colonne
* @param le type de jeton qui a gagné
* @param variable pour trouver une colonne avec des jetons
* @return le nombre de jetons alligné sur une diagonale droite au maximum
*/
int check_diagonaled (Grid g1, int colonne, char jeton,int x);

/**
* verifie si joueur a alligné le bon nombre de jeton sur une diagonale gauche
* @param structure Grid (g1) avec la grille de jeu et sa taille
* @param le numéro de la colonne
* @param le type de jeton qui a gagné
* @param variable pour trouver une colonne avec des jetons
* @return le nombre de jetons alligné sur une diagonale gauche au maximum
*/
int check_diagonaleg (Grid g1, int colonne, char jeton,int x);

/**
* verifie si la grille de jeu est pleine
* @param structure Grid (g1) avec la grille de jeu et sa taille
* @return 1 si la grille est pleine  et -1 si la grille n'est pas pleine
*/
int check_grille_pleine (Grid g1);

/**
* verifie si la ligne la plus basse de la grille de jeu est pleine
* @param structure Grid (g1) avec la grille de jeu et sa taille
* @return 1 si la ligne du bas est vide et 0 si elle ne l'est pas
*/
int check_ligne_bas_vide(Grid g1);

/**
* trouve à quelle hauteur le dernier jeton a été posé
* @param structure Grid (g1) avec la grille de jeu et sa taille
* @param une variable pour savoir a quelle colonne a été posé le dernier jeton
* @return le numero de la ligne où a été posé le dernier jeton
*/
int trouver_x (Grid g1, int colonne);

/**
* verifie si la grille est pleine (donc si il y a égalité) et demende à l'utilisateur si il veut continuer à jouer
* @param structure Grid (g1) avec la grille de jeu et sa taille
* @return 1 si l'utilisateur veut quitter et -1 si l'utilisateur veut continuer
*/
int check_egalite (Grid g1);

#endif //PROJET_IFB_BERGELIN_HERBILLON_GINER_FCT_CHECK_H
