/**�crivez un programme qui demande la vitesse en kilom�tres par heure (km/h) et la transforme en m�tres par seconde (m/s).
Formule :
```
m/s = km/h * 0.27778
```
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    float vitesseKMparHeure;
    printf("Quelle est la vitesse en kilom�tres par heure: ");
    scanf("%f", &vitesseKMparHeure);
    printf("La vitesse en m�tres par seconde est: %.5f", vitesseKMparHeure * 0.27778);
    return 0;
}
