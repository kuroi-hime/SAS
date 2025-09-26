/**Challenge 8 : Fonction de Vérification de Parité
Écrivez une fonction en C qui vérifie si un entier est pair ou impair.
La fonction doit prendre un entier en paramètre et retourner 1 si l'entier est pair 
et 0 s'il est impair. Créez un programme principal qui utilise cette fonction pour 
afficher si un nombre est pair ou impair.
*/
#include<stdio.h>
int estPair(int entier){
	return (entier%2)? 1:0;
}

void main(){
	int entier;
	
	printf("Entrez un entier: ");
	scanf("%d", &entier);
//	(estPair)?printf("pair"):printf("impair");
	printf();
}
