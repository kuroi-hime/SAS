/** �crivez un programme qui demande la temp�rature en Celsius et la transforme en Kelvin.
    Formule :
    ```
    K = C + 273.15
    ```
 */

#include<stdio.h>

int main(int argc, char const *argv[])
{
    float temperature;
    printf("Quelle est la temp�rature en Celsius: ");
    scanf("%f", &temperature);
    printf("La temperature est %.3f en Kelven", temperature + 273.15);
    return 0;
}
