/**Challenge 2 : Structure avec Tableau
�crivez un programme C qui d�finit une structure pour repr�senter un �tudiant avec les champs nom, prenom, 
et un tableau d'entiers pour stocker les notes. Assignez des valeurs aux champs et aux notes, 
puis affichez les informations de l'�tudiant.
*/

#include<stdio.h>
#define longueurChaineMax 50
#define nbrNotesMax 10

typedef struct etudiant{
	char nom[longueurChaineMax];
	char prenom[longueurChaineMax];
	int notes[nbrNotesMax];
}etudiant;

void main(){
	etudiant e = {"hdz dzhbjd", "dhbzjhd dbd", {1, 2, 4}};
	
	printf("L'�tudiant: %s %s dont les notes sont:\n %d %d %d", e.nom, e.prenom, e.notes[0], e.notes[1], e.notes[2]);
}
