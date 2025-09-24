/**Écrivez un programme qui demande la distance en kilomètres et la transforme en yards.
	Formule :
	```
	Yards = Km * 1093.61
	```
*
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    float distanceKM;
    printf("Quelle est la distance en kilomètres: ");
    scanf("%f", &distanceKM);
    printf("La distance en yards est: %.3f", distanceKM * 1093.61);
    return 0;
}
