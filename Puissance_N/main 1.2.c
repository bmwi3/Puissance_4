int main () {
  int n, nombre_de_joueur;
  
 //printf le logo
  
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
  
  
  
}
