int trouver_x (Grid g1, int colonne, char jeton ){  // cette fonction sert a trouver la hateur du dernier jeton poser
    int x = 0, y = colonne - 1; // x étant la varible de hateur et y la largeur du dernier jeton poser dans la grille

    while (g1.grille[x][y]!='O' && g1.grille[x][y]!='X' && x<g1.largeur-1){ // on cherche a trouver a qu'elle hauteur a était poser le dernier jetons
        x++;
    }
    return x;
}

int check_colonne (Grid g1, int colonne, char jeton, int x){        // cette fonction sert a regarder si le dernier jeton est aligner avec n jeton sur la colonne
    int y = colonne - 1,compteur_colonne = 1;                       // compteur_colonne est le nombre de jeton aligner en colonne
    int c = 1,j = 0;                                                // c est une varible qui donne l'information si le jeton en dessous est identique ou non

    do{                                                             // on vérifie si le jeton du dessous est différent ou si on a déja n jeton aligner
        j++;
        if (x+j > g1.largeur-1){                                    // on regarde si le jeton en dessous est bien dans le tableau

            c = 0;                                                  // le jeton est dessous est hors de la grille
        }else if (g1.grille[x + j][y] != jeton ){                   // on compare le dernier jeton jouer avec celui d'en dessous
            c = 0;                                                  // le jeton en dessous est différent
        }
        compteur_colonne += c ;                                     // le compteur de colonne prrend 1 si jeton d'en dessous identique et 0 sinon
        
    } while (c != 0 && compteur_colonne != g1.largeur-2);    

    return compteur_colonne;                                        // on retourne le nombre de jeton aligné en colonne
}

int check_ligne (Grid g1, int colonne, char jeton,int x){           //compte le nombre de jeton aligner en ligne
    int y = colonne - 1,j = 0,compteur_ligne = 1;
    int ld = 1, lg = 1;

    do{                                                             // on vérifie si les jetons de droite et de gauche sont différent du derniere pauser ou si on a déja n jeton aligner
        j++;
        if (g1.largeur -1 < y +j){                                  // on regarde si on se sort pas de la grille a droite
            ld = 0;
        } else if (g1.grille[x][y+ j] != jeton ){                   // on compare le dernier jeton jouer avec ceux de sa droite
            ld = 0;
        }


        if ( y - j < 0){                                            // on regarde si on ne sort pas de la grille a gauche
            lg = 0;
        }else if (g1.grille[x][y- j] != jeton ){                    // on compare le dernier jeton jouer avec ceux de sa gauche
            lg = 0;
        }

        compteur_ligne += ld + lg ;                                 // compteur_ligne compte le nombre de jeton aligner sur la ligne

    } while (ld + lg != 0 && compteur_ligne != g1.largeur-2);

    return compteur_ligne;                                          // on retourne le nombre de jeton aligné sur la ligne
}

int check_diagonaled (Grid g1, int colonne, char jeton, int x){     // cette fonction sert a regarder si le dernier jeton est aligner avec n jeton sur la diagonale
    int y = colonne - 1,j = 0,compteur_diagonaled = 1;
    int bd = 1, hg = 1;

    do {                                                            // on vérifie si les jeton dans la diagonale sont different du duernier jeton poser ou qu'il y est déja n jeton aligner
        
        j++;
        
        if (x+j > g1.largeur-1){                                    //on regarde si on ne sort pas de la grille en bas
            bd = 0;
        }else if (g1.largeur -1 < y +j ){                           //on regarde si on ne sort pas de la grille a droite
            bd = 0;
        }else if (g1.grille[ j+ x ][y + j] != jeton ){              // on compare le dernier jeton jouer avec celui en bas a droite
            bd = 0;
        }

        if (x - j<0){                                               //on regarde si on ne sort pas de la grille en haut
            hg = 0;
        } else if ( y - j < 0) {                                    //on regarde si on ne sort pas de la grille a gauche
            hg = 0;
        }else if (g1.grille[x- j][y- j] != jeton ){                 // on compare le dernier jeton jouer avec celui en haut a gauche
            hg = 0;
        }

        compteur_diagonaled += hg + bd;                             // on compte le nombre de jeton aligner
    }while(hg + bd != 0&& compteur_diagonaled!= g1.largeur-2);
    
    return compteur_diagonaled;                                     // on retourne le nombre de jeton aligner en diagonale
}

int check_diagonaleg (Grid g1, int colonne, char jeton, int x){     // cette fonction sert a regarder si le dernier jeton est aligner avec n jeton sur la diagonale
    int y = colonne - 1,j = 0,compteur_diagonaleg = 1;
    int bg = 1, hd = 1;
   
    do {                                                            // on vérifie si les jeton dans l'autre diagonale sont different du duernier jeton poser ou qu'il y est déja n jeton aligner
        
        j++;
        
        if (x+j > g1.largeur-1){                                    //on regarde si on ne sort pas de la grille en bas
            bg = 0;
        }else if ( y - j < 0) {                                     //on regarde si on ne sort pas de la grille a gauche
            bg = 0;
        }else  if (g1.grille[x+ j][y- j] != jeton ){                // on compare le dernier jeton jouer avec celui en bas a gauche
            bg = 0;
        }


        if (x - j<0){                                               //on regarde si on ne sort pas de la grille en haut
            hd = 0;
        }else if (g1.largeur -1 < y +j ){                           //on regarde si on ne sort pas de la grille a droite
            hd = 0;
        }else if (g1.grille[x- j][y+ j] != jeton ){                 // on compare le dernier jeton jouer avec celui en haut a droite
            hd = 0;
        }

        compteur_diagonaleg += hd + bg;                             // on compte le nombre de jeton aligner


    }while(hd + bg != 0 && compteur_diagonaleg != g1.largeur-2);
    
    return compteur_diagonaleg;                                     // on retourne le nombre de jeton aligner en diagonale
}
}

int  check_winner(Grid g1, int colonne,char jeton) {                // cette fonction sert a regarder si n jeton sont aligner en ligne, colonne ou en diagonale
    int x  = trouver_x ( g1, colonne, jeton );



    if (check_ligne (g1,colonne,jeton,x) == g1.largeur - 2 ||  check_colonne (g1, colonne, jeton, x) == g1.largeur - 2 || check_diagonaled (g1, colonne, jeton, x) == g1.largeur - 2 || check_diagonaleg (g1, colonne, jeton, x) == g1.largeur - 2) {
                                                                    // on regarder si les fonction qui compte le nombre de jeton aligner retourne n 
        if (jeton == 'O') {
            printf("joueur 1 gagne bravo vous avez gagner\n");
            return 0;
            
        } else {
            printf("joueur 2 gagne bravo vous avez gagner\n");
            return 1;
        }
    }
    return -1;
}

int check_grille_pleine (Grid g1,int colonne,char jeton){           // cette fonction sert a regarder si la grille est complétement remplis
    int compteur_egalite = 0;
    int rejouer;
    int x = trouver_x ( g1, colonne, jeton );
    
    if (x==0) {                                                     // regarde si le dernier jeton est dans la ligne du haut
        do {                                                        // on compte le nombre de jeton qu'il y a dans la ligne du haut
            if (g1.grille[0][compteur_egalite] != ' ') {            // à chaque fois qu'une case de la ligne du haut n'est pas vide on incrémente
                compteur_egalite++;
            }

        } while (g1.grille[0][compteur_egalite] != ' '&& compteur_egalite !=g1.largeur);            

        if (compteur_egalite == g1.largeur ) {                      
            
            printf("grille pleine voulait vous continué ?\n1 pour continuer\n2 pour quitter\n");
            do {
                
                scanf("%d", &rejouer);
                if (rejouer != 1 && rejouer != 2 ){

                    printf("Impossible, choisir 1 ou 2/n\n");
                }
            }while (rejouer != 1 && rejouer != 2 );
            
            if (rejouer == 2 ){
                return 1;
            }
        }
    }
    return -1;
}

int check_ligne_bas_pleine(Grid g1){

    int compteur_egalite=0;

    do {
        if (g1.grille[g1.largeur-1][compteur_egalite] == ' ') {
            compteur_egalite++;
        }

    } while (g1.grille[g1.largeur-1][compteur_egalite] == ' ');

    if (compteur_egalite == g1.largeur) {
        return 1;
    } else{
        return 0;
    }

}
