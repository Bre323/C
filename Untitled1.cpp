#include <stdio.h>
#include <stdlib.h>

int a, b;
int soma = a + b;
int sub = a - b;
int multi = a * b;
int divi = a/b;

int main(){
	printf("Digite um valor: ");
	scanf("%i", &a);
	printf("\nDigite mais um valor: ");
	scanf("%i", &b);
	
	printf("Soma de %i e %i igual a %i", a, b, soma);
	printf("Subtracao de %i e %i igual a %i", a, b, sub);
	printf("Multiplicacao de %i e %i igual a %i", a, b, multi);
	printf("Divisao de %i e %i igual a %i", a, b, divi);
	
	return 0;
}

