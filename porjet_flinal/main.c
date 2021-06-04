#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonction.h"
#include "fct_save.h"

int main () {
    FILE*fptr;
    srand(time(NULL));
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

             printf("choisir n le nombre de jeton a aligner, choix de n entre 3 et 20\n");
             do{
                  scanf("%d",&n);
                 if (n < 3 || n > 20) {
                     printf("Impossible, choisir n entre 3 et 20\n");
                  }
             } while (n < 3 || n > 20 );
             g1.largeur = g1.hauteur = nbcolonne = n+2;





             break;

         case 2:
               i=load(fptr,&g1,&nbcolonne,joueur1,joueur2);
               printf("partie charge\n");
               printf("Ahh vous revoila %s et %s!\n",joueur1,joueur2);
               break;

            case 3:
               return 0;
         default:
            {}
     }


     if (start == 1){
         initialise(&g1);



         if (nombre_de_joueur == 2){
             printf("entrer le nom du participant 1\n");
             scanf("%s",joueur1);
             printf("entrer le nom du participant 2\n");
             scanf("%s",joueur2);
         }else {
             printf("entrer le nom du participant\n");
             scanf("%s",joueur1);
             strcpy(joueur2,"ia");
             ia = 1;
         }
         if (player == 1){
             printf("%s est le joueur 1 (vous jouez le O)\n",joueur1);
             printf("%s est le joueur 2 (vous jouez  le X)\n",joueur2);
             ia = 0;
         } else{
             printf("%s est le joueur 1 (vous jouez le O)\n",joueur2);
             printf("%s est le joueur 2 (vous jouez  le X)\n",joueur1);
         }



     }
        show_grid(g1);






        do {

            if (i % 2 == 0) {
                jeton = 'O';
                player = 1;
            } else {
                jeton = 'X';
                player = 2;
            }

            if (ia%2 == 1){
                colonne =IA(g1,jeton);

                printf("\n\nIa joue en %d\n",colonne);
            }else {
                printf("Joueur %d a vous !\n", player);



                //int choice = option_choice();


                switch (option_choice(g1)) {
                    case 1:
                        do {
                            printf("Dans quelles colonnes voulez-vous placer votre jeton?\n");
                            scanf("%d", &colonne);
                        } while (add_token_bis(g1, jeton, colonne) == 0);
                        break;

                    case 2:
                        do {
                            printf("Dans quelles colonnes voulez-vous retirer un jeton?\n");
                            scanf("%d", &colonne);
                        } while (remove_token(g1, jeton, colonne) == 0);
                        break;

                    case 3:
                        if (save(g1, i,joueur1,joueur2) == 1) {
                            printf("sauvegarde reussi");
                            return 0;
                        } else {
                            printf("erreur de sauvegarde...");
                        }
                        break;

                    default: {
                    }
                }
            }

            show_grid(g1);

            i++;

            if (nombre_de_joueur == 1){
                ia++;
            }

        } while(check_winner(g1,colonne, jeton) == -1 && check_grille_pleine(g1,colonne,jeton) == -1);


        printf("Voulez-vous recommencer?1.oui 2.non\n");
        scanf("%d",&replay);

    } while(replay==1);



}
