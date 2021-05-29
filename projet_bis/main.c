#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "fonction.h"
#include "fct_save.h"

int main () {
    FILE*fptr;
    int x=0;
    int n=0,colonne=0, nombre_de_joueur=0,start=0;
    srand(time(NULL));
    Grid g1;
    int replay=0;
    int i=0;

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
            load(fptr,g1);
            printf("partie chargé\n");
            return 0;
            break;

        case 3:
            return 0;
        default:
        {}
    }
    g1.largeur = n+2;
    g1.hauteur = n+2;

    initialise(&g1);

    do {

        int alea=rand()%2;
        char jeton,joueur1[26], joueur2[26];
        int player=alea%2+1;


        if (nombre_de_joueur == 2){
            printf("entrer le nom du joueur 1\n");
            scanf("%s",joueur1);
            printf("entrer le nom du joueur 2\n");
            scanf("%s",joueur2);
        }else {
            printf("entrer le nom du joueur 1\n");
            scanf("%s",joueur1);
            strcpy(joueur2,"ia");
        }

        printf("joueur %d a vous de commencez\n",player);

        do {
            if (i%2==0) {
                jeton='O';
                player=1;
            }
            else {
                jeton='X';
                player=2;
            }
            printf("Joueur %d a vous !\n",player );
            //show_grid(g1);

            int choice=option_choice();

            switch(choice) {
                case 1:
                    do {
                        printf("Dans quelles colonnes voulez-vous placer votre jeton?\n");
                        scanf("%d",&colonne);
                    } while (add_token_bis(g1,jeton,colonne,&x)==0);
                    break;

                case 2:
                    do {
                        printf("Dans quelles colonnes voulez-vous retirer un jeton?\n");
                        scanf("%d",&colonne);
                    } while (remove_token(g1,jeton,colonne)==0);
                    break;

                case 3:
                    if (save(fptr,g1,i)==1) {
                        printf("sauvegarde reussi");
                        return 0;
                    }else{
                        printf("erreur de sauvegarde...");
                    }
                    break;

                default:
                {}
            }

            show_grid(g1);

        //printf("%d",x);
//check_winner(g1,n);

            i++;
        } while(i<5 );//check_winner(g1,n)==1 || check_winner(g1,n)==0);


        printf("Voulez-vous recommencer?1.oui 2.non\n");
        scanf("%d",&replay);

    } while(replay==1);



}