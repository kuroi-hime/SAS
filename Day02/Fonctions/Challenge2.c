/**Challenge 2 : Fonction de Multiplication
�crivez une fonction en C qui prend deux entiers en param�tres et retourne leur produit. 
Cr�ez un programme principal qui utilise cette fonction pour afficher le produit de deux nombres.
*/
#include<stdio.h>

int produit(int entier1, int entier2){
	return entier1*entier2;
}

void main(){
	int a=3, b=4;
	
	printf("Le produit de %d et %d est: %d.", a, b, produit(a, b));
}
