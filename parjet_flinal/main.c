#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonction.h"
#include "fct_save.h"
#include "fonction_check.h"
#include "grid.h"

int main () {
    FILE*fptr;
    srand(time(NULL));  //on initialise le temps a 0
    logo();
    printf("Bienvenue au puissance N \n");
    int replay=0,nbcolonne,player=rand()%2+1;
    char joueur1[26], joueur2[26],jeton;


    do {

        int n=0,colonne=0, nombre_de_joueur=0,start=0;
        Grid g1;
        int i=0, ia=0;

        printf("Nouvelle partie : 1 \nCharger un partie : 2 \nQuitter : 0\n");

        do {
            scanf("%d", &start);    //on lit le choix du joueur
            if ((start != 0 )&& (start != 1) && (start != 2))  //on verifie ce que l'utilisateur a entré avec un message d'erreur
            {
                printf("Impossible, choisir 0, 1 ou 2/n");
            }
        }while ((start != 0 ) && (start != 1) && (start != 2));

        switch (start) {   //on pose 3 cas differents selon le choix de l'utilisateur

            case 1: //si l'utilisateur souhaite commencer une nouvelle partie

                printf("combien de joueur: 1 ou 2\n");   //on demande le nombre de joueur pour savoir si l'IA va jouer

                do {
                    scanf("%d", &nombre_de_joueur);

                    if ((nombre_de_joueur != 1) && (nombre_de_joueur != 2)) {   //verification de ce que rentre l'utilisateur avec message d'erreur
                        printf("Impossible, choisir 1 ou 2\n");
                    }
                }while ((nombre_de_joueur != 1 ) && (nombre_de_joueur != 2));

                printf("choisir le nombre de jeton a aligner pour gagner (choisir entre 3 et 20)\n");  //on demande au joueur le nombre de jeton a alligner pour gagner

                do{    //verification de ce que rentre l'utilisateur avec message d'erreur
                    scanf("%d",&n);
                    if (n < 3 || n > 20) {
                        printf("Impossible, choisir n entre 3 et 20\n");
                    }
                } while (n < 3 || n > 20 );

                g1.largeur = g1.hauteur = nbcolonne = n+2; //on initialise la taille du tableau a n+2 case

                initialise(&g1);   //on initialise la grille a '_'

                if (nombre_de_joueur == 2){    //si deux personnes joue: on demande les deux nom
                    printf("entrer le nom du participant 1\n");
                    scanf("%s",joueur1);
                    printf("entrer le nom du participant 2\n");
                    scanf("%s",joueur2);
                }
                else {    //si une seul personne joue on lui demande son nom et on pose l'IA comme joueur 2
                    printf("entrer le nom du participant\n");
                    scanf("%s",joueur1);
                    strcpy(joueur2,"ia");
                    ia = 1;
                }

                if (player == 1){  //on choisi de maniere random qui est le joueur 1 et qui est le joueur 2 avec la variable player
                    printf("%s est le joueur 1 (vous jouez le O)\n",joueur1);
                    printf("%s est le joueur 2 (vous jouez  le X)\n",joueur2);
                    ia = 0;
                }
                else{
                    printf("%s est le joueur 1 (vous jouez le O)\n",joueur2);
                    printf("%s est le joueur 2 (vous jouez  le X)\n",joueur1);
                }
                break;

            case 2:    //si l'utilisateur souhaite chargé une partie

                i=load(fptr,&g1,nbcolonne,joueur1,joueur2); //on charge tous les elements d'un fichier avec la fonction load et on donne a i la nouvelle valeur que retourne load pour savoir a qui c'est de jouer

                printf("partie charge\n");
                printf("Ahh vous revoila %s et %s!\n",joueur1,joueur2);
                printf("%s vous etes les 'O' et %s vous etes les 'X'\n",joueur1,joueur2);
                break;

            case 0: //si l'utilisateur souhaite quitter
                return 0;
                break;
            default:
            {}
        }

        show_grid(g1);  //on montre la grille avant de commencer pour facilité la saisi de l'utilisateur

        do {

            if (i % 2 == 0) {   //le joueur 1 (choisi aléatoirement) va jouer en premier et grace à la variable i ça alternera
                jeton = 'O';
                player = 1;
            } else {
                jeton = 'X';
                player = 2;
            }

            if (ia % 2 == 1){   //meme chose si il n'y a qu'un jouer et une IA
                colonne =IA(g1,jeton,colonne);

                printf("\n\nIa joue en %d\n",colonne);
            }else {
                printf("Joueur %d a vous !\n", player);



                //int choice = option_choice();


                switch (option_choice(g1)) {    //avec la fonction otion_choice le joueur don c'est le tour choisi entre ajouter un jeton, en retirer un ou sauvegarder et quitter
                    case 1: //si le joueur choisi d'ajouter un jeton
                        do {
                            printf("Dans quelles colonnes voulez-vous placer votre jeton?\n");
                            scanf("%d", &colonne);
                        } while (add_token_bis(g1, jeton, colonne) == 0);   //on appel add_token pour que le jeton soit ajoutter dans la case que l'utilisateur a choisi
                        break;

                    case 2: //si le joueur choisi de retirer un jeton
                        do {
                            printf("Dans quelles colonnes voulez-vous retirer un jeton?\n");
                            scanf("%d", &colonne);
                        } while (remove_token(g1, jeton, colonne) == 0);    //on appel remove_token pour que le jeton soit retirer dans la case que l'utilisateur a choisi
                        break;

                    case 3: //si l'utilisateur choisi de sauvegarder et quitter
                        if (save(g1, i,joueur1,joueur2) == 1) { //on appelle la fonction save pour que les donne rentre dna sle fichier
                            printf("sauvegarde reussi");
                            return 0;
                        } else {
                            printf("erreur de sauvegarde...");
                            return 0;
                        }
                        break;

                    default: {
                    }
                }
            }

            show_grid(g1);  //on affiche la grille pour que le joueur voie ou il en est

            i++;    //on ajoute 1 à i pour que le tour de jeu alterne

            if (nombre_de_joueur == 1){
                ia++;
            }

        } while(check_winner(g1,colonne, jeton) == -1);  //on appel check_winner pour savoir si quelqu'un à gané


        printf("Voulez-vous recommencer?\n\t1.oui\n\t2.non\n"); //on propose a l'utilisateur de rejouer ou quitter
        scanf("%d",&replay);

        free(g1.grille);

    } while(replay==1);
    return 0;



}