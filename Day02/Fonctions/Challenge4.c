/**Challenge 4 : Fonction de Minimum
Écrivez une fonction en C qui prend deux entiers en paramètres et retourne le plus petit des deux.
Créez un programme principal qui utilise cette fonction pour afficher le minimum entre deux nombres.
*/
#include<stdio.h>

int plusPetitEntier(int entier1, int entier2){
	return (entier1 < entier2)? entier1:entier2;
}

void main(){
	int a=3, b=7;
	
	printf("Le plus petit entier entre %d et %d est: %d.", a, b, plusPetitEntier(a, b));
}
