/**Challenge 5 : Fonction de Factorielle
Écrivez une fonction en C qui calcule la factorielle d'un entier positif.
La fonction doit prendre un entier en paramètre et retourner sa factorielle.
Créez un programme principal qui utilise cette fonction pour afficher la factorielle d'un nombre donné.
*/
#include<stdio.h>

int factorielle(int entier){
	size_t i, factorielle=1;
	if(entier>0){
		for(i=2;i<=entier;i++){
  		    factorielle *= i;
		}	
	}
	
	return (entier<0)? 0:factorielle;
}

void main(){
	int nbr = -1;
	if(factorielle(nbr))
	    printf("Le factorielle de %d est: %d.", nbr, factorielle(nbr));
	else
		printf("Le nombre est invalide.");
}
