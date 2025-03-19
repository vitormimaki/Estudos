#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	
	int n, p, r, soma = 0;
	
	setlocale(LC_ALL, "portuguese");
	

	do {
		printf("N = ");
		scanf("%d", &n);
		if (n == 0) {
			printf("\nValor Inválido!");
			system("pause > nul");
			system("cls");
		}
	} while (n == 0);

	do {
		printf("P = ");
		scanf("%d", &p);
		if (p == 0) {
			printf("\nValor Inválido!");
			system("pause > nul");
			system("cls");
		}
	} while (p == 0);
	
	do {
		printf("R = ");
		scanf("%d", &r);
		if (r == 0) {
			printf("\nValor Inválido!");
			system("pause > nul");
			system("cls");
		}
	} while (r == 0);
		
	soma += p;
	printf("\n%d ", p);
	
	for (int i = 1; i < n; ++i) {
		p *= r;
		soma += p;
		printf("%d ", p);
	}
	
	printf("\nSoma = %d", soma);
	system("pause > nul");
	
	return 0;
}
