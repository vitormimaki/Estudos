#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que leia um n�mero
inteiro e informe se ele � par ou �mpar.*/

int main(void) {
	
	int num;
	
	printf("Escolha um numero: ");
	scanf("%d", &num);
	
	if (num % 2 == 0) {
		printf("O numero %d e par!\n\n", num);
	} else {
		printf("O numero %d e impar!\n\n", num);
	}
	
	system("pause");
	
	return 0;
	
}
