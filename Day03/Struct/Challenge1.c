/**Challenge 1 : D�finition et Utilisation de Structure
�crivez un programme C qui d�finit une structure pour repr�senter une personne avec les champs nom, prenom, et age. 
Cr�ez une variable de cette structure, assignez des valeurs aux champs, et affichez ces valeurs.
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
