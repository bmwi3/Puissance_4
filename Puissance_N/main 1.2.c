#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "fonctions.h"

int main () {
    int n=0,colonne=0, nombre_de_joueur=0,start=0;
    srand(time(NULL));
    Grid g1;
    char replay;


    logo();
    printf("Bienvenue au puissance N \nNouvelle partie : 1 \nPartie chargée : 2 \nQuitter : 0\n");

    do {
        scanf("%d", &start);
        if ((start != 0 )&& (start != 1) && (start != 2))
        {
            printf("Impossible, choisir 0, 1 ou 2/n");
        }
    }while ((start != 0 )&& (start != 1) && (start != 2));

    switch (start) {
        case 1:
            printf("combien de joueur: 1 ou 2\n");
            do {
                scanf("%d", &nombre_de_joueur);

                if ((nombre_de_joueur != 1) && (nombre_de_joueur != 2)) {
                    printf("Impossible, choisir 1 ou 2\n");
                }
            }while ((nombre_de_joueur != 1 ) && (nombre_de_joueur != 2));

            printf("choisir n le nombre de jeton à aligner, choix de n entre 3 et 20\n");
            do{
                scanf("%d",&n);
                if (n < 3 || n > 20) {
                    printf("Impossible, choisir n entre 3 et 20\n");
                }
            } while (n < 3 || n > 20 );


            break;

            case 2:
                //fonction load partie chargé
            break;

            case 3:
            return 0;
            break;
        default:
        {}
    }
    g1.largeur = n+2;
    g1.hauteur = n+2;

    g1.grille = (char**) malloc(sizeof (char*) * g1.largeur);
    for (int i=0;i<g1.largeur;i++){
        g1.grille[i]=(char*) malloc(sizeof (char)*g1.hauteur);
        for (int j=0;j<g1.hauteur;j++){
            g1.grille[i][j] = ' ';
        }
    }

do {
int i=0;
int alea=rand()%2;
char jeton,joueur1[26], joueur2[26],ia="IA";
int player=alea%2+1;


if (nombre_de_joueur == 2){
printf("entrer le nom du joueur 1\n");
scanf("%s",joueur1);
printf("entrer le nom du joueur 2\n");
scanf("%s",joueur2);
}else {
printf("entrer le nom du joueur 1\n");
scanf("%s",joueur1);
strcpy(joueur2,ia);
}

printf("joueur %d a vous de commencez\n",player);


do {
if (i%2==0) {
jeton='O';
player;
}
else {
jeton='X';
player++;
}
printf("Joueur %d à vous !\n",player );
show_grid(g1);

int choice=option_choice();

switch(choice) {
    case 1:

            printf("Dans quelles colonnes voulez-vous placer votre jeton?\n");
            scanf("%d",&colonne);
            add_token_bis(g1,jeton,colonne);

        break;

    case 2:
        //remove_token;
        break;

    case 3:
        printf("fonction savesave") ;
        return 0;
        break;

    default:
        {}
}
printf("gg\n");
show_grid(g1);
    add_token_bis(g1,'X',colonne);
    show_grid(g1);

check_winner(g1,n);
printf("hii");
i++;
printf("%d",i);
} while(check_winner(g1,n)==1 || check_winner(g1,n)==0);

printf("Voulez-vous recommencer?\n");
scanf("%c",replay);

} while(toupper(replay)=='O');



}
