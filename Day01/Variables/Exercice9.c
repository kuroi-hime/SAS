// Challenge 9 : Calcul de la distance entre deux points dans un espace 3D

/** Écrivez un programme C pour trouver la distance entre deux points donnés dans un espace 3D.
    Formule :
    ```
    Distance = √((x2-x1)² + (y2-y1)² + (z2-z1)²)
    ```
*/
#include<stdio.h>
#include<math.h>

void main(int argc, char const *argv[])
{
    int x1=5,x2=6,y1=2,y2=4, z1=6,z2=3;
    float distance;

    distance = sqrt((pow(x2-x1, 2)+pow(y2-y1, 2)+pow(z2-z1, 2)));
    printf("La distance entre le point(%d, %d, %d) et le point(%d, %d, %d) est: %d.\n", x1,y1, z1, x2, y2, z2, distance);
}
