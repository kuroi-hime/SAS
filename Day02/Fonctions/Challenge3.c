/**Challenge 3 : Fonction de Maximum
�crivez une fonction en C qui prend deux entiers en param�tres et retourne le plus grand des deux.
Cr�ez un programme principal qui utilise cette fonction pour afficher le maximum entre deux nombres.
*/
#include<stdio.h>

int plusGrandEntier(int entier1, int entier2){
	return (entier1 > entier2)? entier1:entier2;
}

void main(){
	int a=4, b=2;
	
	printf("Le plus grand nombre entre %d et %d est: %d.", a, b, plusGrandEntier(a, b));
}
