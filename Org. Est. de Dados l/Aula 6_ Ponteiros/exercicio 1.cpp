//Fa�a um programa que leia 1 n�mero inteiro e 1 n�mero float.
//Depois apresente o valor e o endere�o de mem�ria destas vari�veis.

#include <stdio.h>
#include <stdlib.h>

main () {
	int n1;
	printf("Informe o valor do int:");
	scanf("%i",&n1);
	float n2;
	printf("Informe o valor do float:");
	scanf("%f",&n2);
	printf("Valor do int: %i\n", n1);
	printf("Endereco de memoria do int: %p\n\n", &n1);
	printf("Valor do float: %.1f\n", n2);
	printf("Endereco de memoria do float: %p\n\n", &n2);
	system("PAUSE");
}
