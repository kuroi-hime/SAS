/**Challenge 1 : Tri à Bulles
Écrivez un programme C qui implémente l'algorithme de tri à bulles pour trier un tableau d'entiers. 
Affichez le tableau avant et après le tri.
 */

#include <stdio.h>

void triParBulles(int tab[], size_t n){
     size_t i, j;
     int temp;

     for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(tab[j]>tab[j+1]){
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
     }
}

void afficherTab(int tab[], size_t n){
    size_t i;

    for ( i = 0; i < n; i++)
    {
        printf("%d\t", tab[i]);
    }
    
}

void remplirTab(int tab[], size_t n){
	size_t i;
	
	for(i=0;i<n;i++){
		printf("Entrez le %d element: ", i+1);
		scanf("%d", &tab[i]);
	}
}

void main(){
    size_t n;

    printf("Entrez la taille du tableau: ");
    scanf("%zu", &n);

    int tab[n];

	remplirTab(tab, n);
    printf("Le tab avant tri:\n");
    afficherTab(tab, n);
    triParBulles(tab, n);
    printf("Le tab apres le tri:\n");
    afficherTab(tab, n);
}
