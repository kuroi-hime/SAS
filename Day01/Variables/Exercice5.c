/**�crivez un programme qui demande la temp�rature en Celsius et affiche l'�tat de l'eau � cette temp�rature (solide, liquide, gaz).
R�gle :

* C < 0 : Solide
* 0 <= C < 100 : Liquide
* C >= 100 : Gaz
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    float temperatureCelsius;
    printf("Quelle est la temp�rature en celsius: ");
    scanf("%f", &temperatureCelsius);
    if (temperatureCelsius < 0){
    	printf("Solide");
	}
    else if (temperatureCelsius>=0 && temperatureCelsius<100){
    	printf("Liquide");
	}
    else{
    	printf("Gaz");
	}
    return 0;
}
