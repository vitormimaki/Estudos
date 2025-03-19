#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void inicio(void) {
	printf("Arthur de Queiroz\n");
	printf("Vitor Aurélio Saccone Mimaki\n");
	printf("Questão 2:\n");
}

int main(void) {
	
	int n;
	
	setlocale(LC_ALL, "portuguese");
	
	inicio();
	
	do {
		printf("Escolha um Número Par no intervalo [6,32]: ");
		scanf("%d", &n);
		if (n < 6 || n > 32 || n % 2 != 0) {		
			printf("\nO número %d é Inválido\n", n);
		}
	} while (n < 6 || n > 32 || n % 2 != 0);
	
	system("cls");
	inicio();
	printf("\nEntrada: %d", n);
	
	printf("\n\nSaída\n\n");
	
	for(int i = 0; i < n - 1; i++) {
		if(i == 0) {
			printf(" ");
		} else {
			printf("*");
		}
	}
	printf("\n");
	for(int i = 0; i < n; i++) {
		printf("*");
	}
	for(int i = 0; i < n - 4; i++) {
		printf("\n");
		for(int j = 0; j < n; j++) {
			if (j == 0 || j == 1 || j == n - 1 || j == n-2) {
				printf("*");
			} else {
				printf(" ");
			}
		}
	}
	printf("\n");
	for(int i = 0; i < n; i++) {
		printf("*");
	}
	printf("\n");
	for(int i = 0; i < n - 1; i++) {
		if(i == 0) {
			printf(" ");
		} else {
			printf("*");
		}
	}
	system("pause");
	
	return 0;
}
