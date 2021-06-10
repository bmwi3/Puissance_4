//
// Created by julie on 08/06/2021.
//

#include "fct_save.h"


int save(Grid g1,int i,char *joueur1,char *joueur2) {
    FILE*fptr;
    char tab[( g1.largeur - 1)];

    fptr = fopen("save.txt", "w");

    if (fptr == NULL) {//on affiche un message d'erreur si on rencontre un probleme lors de la sauvegarde
        printf("Le fichier save.txt n'existe pas ou n'as pas pu etre charge\n");
        return 0;
    } else {

        fprintf(fptr, "%d %d\n",i,g1.hauteur);//on ecrit dans le fichier save.txt la valeur de i, de la taille du tableau et les noms des deux joueurs
        fprintf(fptr,"%s %s\n",joueur1,joueur2);
    }
    for (int k = 0; k < g1.largeur; k++)//on ecrit dans le fichier save.txt les valeur du tableau ligne par ligne
    {
        strcpy(tab, g1.grille[k]);

        fputs(tab, fptr);
        fputs("\n", fptr);
    }
    fclose(fptr);
    return 1;
}

int load(FILE*fptr,Grid *g1,int colonne,char *joueur1,char *joueur2){
    int i;
    fptr=fopen("save.txt","r");
    if(fptr==NULL) {//on affiche un message d'erreur si le fichier save.txt n'existe pas ou qu'il n'a pas pu etre chargé
        printf(" File named save.txt does not exist or cannot be opened.\n");
        return 0;
    }
    else {
        fscanf(fptr,"%d %d\n",&i,&colonne);//on lit dans le fichier le jouer dont c'est le tour(i) la taille du tableau et le nom des deux joueurs
        fscanf(fptr,"%s %s\n",joueur1,joueur2);

        g1->largeur = g1->hauteur = colonne;
        initialise(g1);//on initialise un tableau de la taille prise dans le fichier et un lui incrémente les valeurs du tableau lu dans le fichier
        for (int j = 0; j < g1->largeur; j++){
            for (int k = 0; k < g1->largeur; k++){
                fscanf(fptr,"%c",&g1->grille[j][k]);


            }
            fscanf(fptr,"\n");
        }
        fclose(fptr);



    }
    return i;//on retourne i pour savoir le joueur dont c'est le tour.



}
