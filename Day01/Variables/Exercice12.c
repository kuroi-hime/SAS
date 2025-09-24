/**### Challenge 12 : Nombre entier à quatre chiffres en ordre inverse
Écrivez un programme C pour afficher un nombre entier à quatre chiffres dans l'ordre inverse sans utiliser de boucle. Par exemple, 
si le nombre entier est 1234, son inverse est 4321.
*/

#include<stdio.h>

int main(){
    int entier[]={1, 2, 3, 4};
    
    printf("Le nombre %d%d%d%d en ordre inverse est: %d%d%d%d.\n", entier[0], entier[1], entier[2], entier[3], entier[3], entier[2], entier[1], entier[0]);
    return  0;
}