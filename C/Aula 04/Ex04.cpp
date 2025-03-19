#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	
	int num, min = 0, max, qnt = 0, soma = 0;
	double media = 0;
	
	setlocale(LC_ALL, "portuguese");
	
	do {
		scanf("%d", &num);
		if (num > 0) {
			qnt++;
			soma += num;
			if (qnt == 1) {
				max = num;
				min = num;
			} else {
				if (num > max) {
					max = num;
				}
				if (num < min) {
					min = num;
				}
			}
		}
	} while (num > 0);
	
	media = (double) soma / qnt;
	
	printf("\nMaior valor: %d e Menor valor: %d\n", max, min);
	printf("Quantidade de Valores: %d e Média: %.2lf\n", qnt, media);
	
	system("pause > nul");
	
	return 0;
}
