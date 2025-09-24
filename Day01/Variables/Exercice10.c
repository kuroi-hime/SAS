/**### Challenge 10 : Volume d'une sphère
Écrivez un programme pour trouver le volume d'une sphère. Prenez le rayon de la sphère en entrée de l'utilisateur.
Formule pour le volume d'une sphère :
```
Volume = (4/3) * π * r³
```
*/

#include<stdio.h>
#include<math.h>
#define pi 3.1415

int main(int argc, char const *argv[])
{
    float rayon;

    printf("Entrez le rayon de sphere: ");
    scanf("%f", &rayon);
    printf("Le volume de ce sphere est: %.2lf", (4.0 * pi  * powf(rayon, 3))/3.0);
    return 0;
}
