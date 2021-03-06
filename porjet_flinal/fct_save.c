//
// Created by julien on 29/05/2021.
//

#include "fct_save.h"




int save(Grid g1,int i,char *joueur1,char *joueur2) 
    FILE*fptr;                                       
    char tab[( g1.largeur - 1)];                   
    fptr = fopen("save.txt", "w");                      // on ouvre le fichier en mode ecriture
    if (fptr == NULL) {                                 //on affiche un message d'erreur si on rencontre un probleme lors de la sauvegarde
        printf(" Le fichier de sauvegarde n'a pas plu etre ouvert\n"); 
        return 0;   // on retourne 0 si il y a eu un problème
    } else {

        fprintf(fptr, "%d %d\n",i,g1.hauteur);  //on ecrit dans le fichier save.txt la valeur de i, de la taille du tableau et les noms des deux joueurs
        fprintf(fptr,"%s %s\n",joueur1,joueur2);
    }
    for (int k = 0; k < g1.largeur; k++)    //on ecrit dans le fichier save.txt les valeur du tableau ligne par ligne
    {
        strcpy(tab, g1.grille[k]);  //on copie la ligne i de notre grille dans notre tableau 

        fputs(tab, fptr);   //on enregistre sur le fichier la premiere ligne qui est notre chaine de caractère a l'aide de fput
        fputs("\n", fptr);
    }
    fclose(fptr);    //on ferme le fichier pour eviter les erreurs
    return 1;    //on retourne 1 si tout c'est bien passé
}

int load(FILE*fptr,Grid *g1,int colonne,char *joueur1,char *joueur2){
    int i;
    fptr=fopen("save.txt","r");     //on ouvre notre fichier en mode lecture
    if(fptr==NULL) {    //on affiche un message d'erreur si le fichier save.txt n'existe pas ou qu'il n'a pas pu etre chargé
        printf(" File named save.txt does not exist or cannot be opened.\n");
        return 0;   //on retourne 0 si il y a eu un problème
    }
    else {
        fscanf(fptr,"%d %d\n",&i,&colonne);//on lit dans le fichier le jouer dont c'est le tour(i) la taille du tableau et le nom des deux joueurs
        fscanf(fptr,"%s %s\n",joueur1,joueur2);

        g1->hauteur=g1->largeur=colonne;
        initialise(g1);//on initialise un tableau de la taille prise dans le fichier et un lui incrémente les valeurs du tableau lu dans le fichier
        for (int j = 0; j < g1->largeur; j++){
            for (int k = 0; k < g1->largeur; k++){
                fscanf(fptr,"%c",&g1->grille[j][k]);//on implemente le tableau caractère par caractère


            }
            fscanf(fptr,"\n");
        }
        fclose(fptr);//on ferme le fichier pour eviter les erreurs



    }
    return i;//on retourne i pour savoir le joueur dont c'est le tour.



}
