/**Écrivez un programme qui demande la température en Celsius et affiche l'état de l'eau à cette température (solide, liquide, gaz).
Règle :

* C < 0 : Solide
* 0 <= C < 100 : Liquide
* C >= 100 : Gaz
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    float temperatureCelsius;
    printf("Quelle est la température en celsius: ");
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
