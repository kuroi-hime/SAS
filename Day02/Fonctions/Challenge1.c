/**Écrivez une fonction en C qui prend deux entiers en paramètres et retourne leur somme. 
Créez un programme principal qui utilise cette fonction pour afficher la somme de deux nombres.
*/
#include<stdio.h>

int somme(int entier1, int entier2){
	return entier1 + entier2;
}

void main(){
	int a=4, b=8;
	
	printf("La somme de %d et %d est: %d", a, b, somme(a, b));
}
