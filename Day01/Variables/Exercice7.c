/**�crivez un programme en C pour calculer la moyenne pond�r�e de trois nombres donn�s par l'utilisateur avec les pond�rations suivantes :

* 1er nombre : pond�ration 2
* 2�me nombre : pond�ration 3
* 3�me nombre : pond�ration 5
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
	float nbr1, nbr2, nbr3, moyenne_ponderee;
	
	printf("Entrez trois nombres: ");
	scanf("%f %f %f", &nbr1, &nbr2, &nbr3);
	moyenne_ponderee = ((nbr1 * 2)+(nbr2 * 3)+(nbr3 * 5))/(2+3+5);
	printf("La moyenne pond�r�e de ces trois nombres est: %.2f", moyenne_ponderee);
	return 0;
}
