/**�crivez un programme en C pour trouver la moyenne g�om�trique de trois nombres saisis par l'utilisateur.
Formule :
```
Moyenne g�om�trique = (a * b * c)^(1/3)
```
*/

#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
	float nbr1, nbr2, nbr3, moyenne_geometrique;
	
	printf("Entrez trois nombres: ");
	scanf("%f %f %f", &nbr1, &nbr2, &nbr3);
	moyenne_geometrique = pow(nbr1*nbr2*nbr3, 1.0/3.0);
	printf("La moyenne g�om�trique des trois nombres saisis est: %.3f", moyenne_geometrique);
	return 0;
}
