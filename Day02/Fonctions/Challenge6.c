/**Challenge 6 : Fonction de Fibonacci
�crivez une fonction en C qui calcule le n-i�me terme de la suite de Fibonacci.
La fonction doit prendre un entier en param�tre et retourner le n-i�me terme.
Cr�ez un programme principal qui utilise cette fonction pour afficher le terme de Fibonacci demand�.
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
	
	printf("Entrez le terme demand�: ");
	scanf("%zu", &termeDemande);
	
	printf("le %zu-i�me terme de la suite de Fibonacci est: %zu", termeDemande, fibonacci(termeDemande));
}
