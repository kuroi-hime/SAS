/**Challenge 5 : Fonction de Factorielle
�crivez une fonction en C qui calcule la factorielle d'un entier positif.
La fonction doit prendre un entier en param�tre et retourner sa factorielle.
Cr�ez un programme principal qui utilise cette fonction pour afficher la factorielle d'un nombre donn�.
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
