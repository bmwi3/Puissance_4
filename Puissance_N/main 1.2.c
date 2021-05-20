#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main () {
  int n, nombre_de_joueur;
  int option_choice(NULL);
  srand(time(NULL));
  
logo()  
 printf("Bienvenue au puissance N /nNouvelle partie : 1 /nPartie chargée : 2 /nQuitter : 0/n");
 
 do 
   scanf("%d",start);
   if (start != ( 0 || 1 || 2)){
      printf("Impossible, choisir 0, 1 ou 2/n");
     }
 while (start != ( 0 || 1 || 2))}
   
 switch( start) ;
  
  cas 1:
    printf("combien de joueur: 1 ou 2/n");
     do 
       scanf("%d",nombre_de_joeur);

       if (nombre_de_joueur != ( 1 || 2)){
       printf("Impossible, choisir 1 ou 2/n");
       }
        while (nombre_de_joueur != ( 1 || 2))}

    printf("choisir n le nombre de jeton à aligner, choix de n entre 3 et 20/n"); 
    do
      scanf("%d",n);
      if (n < 3 || n > 20){
      printf("Impossible, choisir n entre 3 et 20/n");
      while (n < 3 || n > 20 );
      }
        
  break;
  
  cas 2:
    //fonction load partie chargé
  break;
  
  cas 3:
    return 0;
    break;
   default;
  
do {
  int alea=0,i=0,player=0;
  alea=rand()%2;
  char jeton, replay;
  
  do {
    if (i%2==0) {
      jeton='O';
      player=1;
    }
    else {
      jeton='X';
      player=2;
    }
printf("Joueur %d à vous !\n",player );
show_grid(g1);

switch(option_choice);
  case 1:
add_token;
  break;
    
  case 2:
remove_token;
  break;
    
  case 3:
save;
 return 0;
  break;
    
default;

show_grid(g1);
check_winner(g1);
i++;
    
} while(check_winner(g1)==1 || check_winner(g1)==0);

  printf("Voulez-vous recommencer?\n");
  scanf("%c",replay);
  
} while(toupper(replay)=='O');

int option_choice(NULL){
  int choice=0;
  do {
    printf("Voulez vous :\n 1.Ajouter un jeton\n 2.Enlever un jeton\n 3.Sauvegarder et quitter\n");
    scanf("%d",&choice);
  } while(choice!=(1||2||3));
  return choice;
  
}
  
}
