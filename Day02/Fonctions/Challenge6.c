/**Challenge 6 : Fonction de Fibonacci
Écrivez une fonction en C qui calcule le n-ième terme de la suite de Fibonacci.
La fonction doit prendre un entier en paramètre et retourner le n-ième terme.
Créez un programme principal qui utilise cette fonction pour afficher le terme de Fibonacci demandé.
*/
#include<stdio.h>

size_t fibonacci(size_t entier){
	size_t F_n[entier+1], i;
	for(i=0;i<=entier;i++){
		if (i==0 || i==1){
			F_n[i]=i;
		}
		else{
			F_n[i]= F_n[i-1]+F_n[i-2];
		}
	}
	return F_n[entier];
}
 
void main(){
	size_t termeDemande;
	
	printf("Entrez le terme demandé: ");
	scanf("%zu", &termeDemande);
	
	printf("le %zu-ième terme de la suite de Fibonacci est: %zu", termeDemande, fibonacci(termeDemande));
}
