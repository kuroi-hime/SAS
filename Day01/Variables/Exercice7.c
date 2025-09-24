/**Écrivez un programme en C pour calculer la moyenne pondérée de trois nombres donnés par l'utilisateur avec les pondérations suivantes :

* 1er nombre : pondération 2
* 2ème nombre : pondération 3
* 3ème nombre : pondération 5
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
	float nbr1, nbr2, nbr3, moyenne_ponderee;
	
	printf("Entrez trois nombres: ");
	scanf("%f %f %f", &nbr1, &nbr2, &nbr3);
	moyenne_ponderee = ((nbr1 * 2)+(nbr2 * 3)+(nbr3 * 5))/(2+3+5);
	printf("La moyenne pondérée de ces trois nombres est: %.2f", moyenne_ponderee);
	return 0;
}
