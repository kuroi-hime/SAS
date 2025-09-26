/**Challenge 3 : Passage de Structure en Argument
Écrivez un programme C qui définit une structure pour représenter un rectangle avec les champs longueur et largeur. 
Écrivez une fonction qui prend une variable de cette structure en argument et calcule l'aire du rectangle. 
Affichez l'aire dans le programme principal.
*/

#include<stdio.h>

typedef struct rectangle{
	float longueur, largeur;
}rectangle;

float aireRectangle(rectangle r){
	return r.largeur*r.longueur;
}

void main(){
	rectangle r = {2, 5};
	
	printf("L'aire du rectangle en question est: %.2f.", aireRectangle(r));
}
