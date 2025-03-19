#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	int num, cont = 1, qtd = 1, qtdeImp = 0;
	
	setlocale(LC_ALL, "portuguese");
	
	printf("Arthur de Queiroz\n");
	printf("Vitor Aurélio Saccone Mimaki\n");
	printf("Questão 2\n");
	
	do {
		printf("Escolha um Número Ímpar no intervalo [5,49]: ");
		scanf("%d", &num);
		if (num < 5 || num > 49 || num % 2 == 0) {
			printf("\nO número %d é inválido\n", num);
		}
	} while (num < 5 || num > 49 || num % 2 == 0);
	
	for (num = num; num > 0; num--) {
		if (num % 2 != 0) {
			qtdeImp++;
		}
	}
	
	do {
		if (qtd % 2 != 0) {
			for (int i = 1; i <= (qtdeImp - cont); i++) {
				printf(" ");
			}
			for (int i = 0; i < qtd; i++) {
				printf ("*");
			}
			printf("\n");
			cont++;
		}
		qtd++;
	} while (qtd - 1 != qtdeImp * 2);

	cont = qtdeImp - 1;
	for (int i = 0; i < cont; i++) {
		printf(" ");
	}
	printf("|\n");
	for (int i = 0; i < cont-1; i++) {
		printf(" ");
	}
	printf("---\n\n");
	system("pause");
	return 0;
}
