#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"  //on inclut la librairie
#include "fonctions.c"

int main(int argc, char* argv[]) {
logo();
char choice;

    do {
        printf("Bienvenue sur le jeux Puissance N !\nNouvelle partie: N\nCharger une sauvegarde: S\nQuitter: Q\n");
        scanf("%c",&choice);

        choice=toupper(choice);

        switch (choice) {
            case 'N':
                //appelfonctionnouvelle partie
                printf("Nouvelle partie");
                break;
            case 'S':
                //appelfonction charger sauvegarde
                printf("Chargement en cours");
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



return EXIT_SUCCESS;
}

