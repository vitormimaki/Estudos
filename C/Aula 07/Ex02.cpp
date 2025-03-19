#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
	
	int *N, qtde;
	
	setlocale(LC_ALL, "portuguese");
	
	srand(time(NULL));
	do {
		printf("Informe uma Quantidade N: ");
		scanf("%d", &qtde);
		if (qtde <= 0) {
			system("cls");
			printf("Valor Inválido\n");
		}
	} while (qtde <= 0);
	
	N = (int *)malloc(sizeof(int) * qtde);
	
	for(int i = 0; i < qtde; i++) {
		N[i] = rand() % 101;
		printf("N[%d] = %d\n", i, N[i]);
	}
	
	int X, repetiu = 0;
	printf("Informe um Valor X: ");
	scanf("%d", &X);
	
	for(int i = 0; i < qtde; i++) {
		if(N[i] == X && repetiu == 0) {
			printf("O Valor %d está presente no(s) índice(s): ", X);
			repetiu = 1;
		}
		if (N[i] == X) {
			printf("[%d] ", i);
		}
	}
	if (repetiu == 0) {
		printf("O valor %d Não está no Vetor.\n", X);
	}
	free(N);
	system("pause > nul");
	return 0;
}
