/**Écrivez un programme qui demande la vitesse en kilomètres par heure (km/h) et la transforme en mètres par seconde (m/s).
Formule :
```
m/s = km/h * 0.27778
```
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    float vitesseKMparHeure;
    printf("Quelle est la vitesse en kilomètres par heure: ");
    scanf("%f", &vitesseKMparHeure);
    printf("La vitesse en mètres par seconde est: %.5f", vitesseKMparHeure * 0.27778);
    return 0;
}
