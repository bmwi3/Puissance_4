#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"  //on inclut la librairie



int main(int argc, char* argv[]) {
    logo();
    char choice,jeton;
    int num_col=0, N;
    Grid g1;

    do {
        printf("Bienvenue sur le jeux Puissance N !\nNouvelle partie: N\nCharger une sauvegarde: S\nQuitter: Q\n");
        scanf("%c",&choice);

        choice=toupper(choice);

        switch (choice) {
            case 'N':
                //appelfonctionnouvelle partie
                printf("Nouvelle partie");
                action();
                break;
            case 'S':
                //appelfonction charger sauvegarde
                printf("Chargement en cours");
                action();
                break;
            case 'Q':
                //quitter
                printf("bye");
                break;
            default:
                ;
        }
        vider_buffer(); //permet de liberer le charactère dans choice

    } while (choice!='S'&& choice!='N'&& choice!='Q');

   
    
    printf("entrer la valeur de N:\n");
    scanf("%d",&N);
    while(N<0){
        printf("erreur, N doit etre un entier positif!!\n");
        printf("entrer la valeur de N:\n");
        scanf("%d",&N);
    }
    g1.largeur = N+2;
    g1.hauteur = N+2;

    g1.grille = (char**) malloc(sizeof (char*) * g1.largeur);
    for (int i=0;i<g1.largeur;i++){
        g1.grille[i]=(char*) malloc(sizeof (char)*g1.hauteur);
        for (int j=0;j<g1.hauteur;j++){
            g1.grille[i][j] = '_';
        }
    }

    show_grid(g1);

    do {
        printf("\nentrez une colone : ");
        scanf("%d",&num_col);
        show_grid(g1);
    }
    while(add_token_bis(g1.grille, jeton, num_col-1, g1.largeur)==0);

    show_grid(g1);

    return 0;
}
