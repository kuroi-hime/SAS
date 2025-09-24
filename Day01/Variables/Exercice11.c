/**### Challenge 11 : Surface d'un rectangle
Écrivez un programme pour trouver la surface d'un rectangle. Prenez la longueur et la largeur du rectangle en entrée de l'utilisateur.
Formule pour la surface d'un rectangle :
```
Surface = longueur * largeur
```
*/

#include<stdio.h>

int main(){

    float largeur, longueur;

    printf("Entrez la largeur du rectangle: ");
    scanf("%f", &largeur);
    printf("Entrez la longueur du rectangle: ");
    scanf("%f", &longueur);
    printf("La surface du rectangle est: %.2lf", largeur*longueur);
    return  0;
}