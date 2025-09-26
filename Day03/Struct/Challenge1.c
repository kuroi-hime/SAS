/**Challenge 1 : Définition et Utilisation de Structure
Écrivez un programme C qui définit une structure pour représenter une personne avec les champs nom, prenom, et age. 
Créez une variable de cette structure, assignez des valeurs aux champs, et affichez ces valeurs.
*/
#include<stdio.h>
#define longueurChaineMax 50

typedef struct personne{
	char nom[longueurChaineMax];
	char prenom[longueurChaineMax];
	int age;
}personne;

void main(){
	personne p = {"bshzb hzbhjb", "HGHHV gvgv", 17};
	
	printf("Je suis %s %s et j'ai %d ans.\n", p.nom, p.prenom, p.age);
}
