/**Deux nombres r�els, a et b, sont saisis au clavier. Calculez et affichez a + b, a - b, a * b, et a / b avec pr�cision d�cimale.
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
	float a, b;
	printf("Entrez deux nombres r�els: ");
	scanf("%f %f", &a, &b);
	printf("\n%.3f + %.3f = %.3f", a, b, a+b);
	printf("\n%.3f - %.3f = %.3f", a, b, a-b);
	printf("\n%.3f * %.3f = %.3f", a, b, a*b);
	if (b){
		printf("\n%.3f / %.3f = %.3f", a, b, a/b);
	}
	
	return 0;
}
