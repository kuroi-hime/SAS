/**### Challenge 13 : Affichage des valeurs binaire et hexadécimale équivalentes
Écrivez un programme C pour afficher la valeur équivalente en binaire et en hexadécimal. 
Entrez un nombre entier et affichez ses valeurs équivalentes en binaire et en hexadécimal.
*/

#include<stdio.h>
#include<math.h>

int main(){
    int entier;

    printf("entrez un entier:");
    scanf("%d",&entier);

    int q=entier, r, nbrBits=0;

    do
    {
        q/=2;
        nbrBits++;
    } while (q);
    
    size_t bits[nbrBits], i=0;
    q=entier;
    do
    {
        bits[i++]=q%2;
        q/=2;
    } while (q);
    
    printf("La valeur binaire equivalente est: ");
    for(i=nbrBits;i>0;i--){
        printf("%zu",bits[i-1]);
    }
    printf("\nLa valeur hexadecimale equivalente est: %x", entier);
    return  0;
}