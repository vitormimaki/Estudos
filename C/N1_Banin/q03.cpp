#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	
	setlocale(LC_ALL, "portuguese");
	
	printf("Arthur de Queiroz\n");
	printf("Vitor Aurélio Saccone Mimaki\n");
	printf("Questão 3\n");
	
	int min, max, soma, qtde, i, j, primo;
	
	do {
		printf("\nEscolha um Número Mínimo para o Intervalo: ");
		scanf("%d", &min);
		if (min <= 1) {
			printf("\nO número deve ser maior que 1");
		}
	} while (min <= 1);
	
	do {
		printf("\nEscolha um Número Máximo para o Intervalo: ");
		scanf("%d", &max);
		if (max <= min) {
			printf("\nO Número deve ser maior que o Mínimo");
		}
	} while (max <= min);
	
	soma = 0;
	qtde = 0;
	
	printf("Min = %d e Máx = %d\n", min, max);
	
	//Primo = SÓ divisivel por 1 e por ele mesmo
	
	for(i = min; i <= max; i++) { //Começa do Mínimo
		primo = 1; //Não sei se é primo, mas roda o laço ae
		for(j = 2; j < i && primo == 1; j++) { //Conta de j até i
			if(i % j == 0) { //Se há divisores
				primo = 0; //Não é Primo
			} else { //Se não há divisores
				primo = 1; //É primo
			}
		}
		if(primo == 1) {
			printf("%d\n", i);
			soma += i;
			qtde++;
		}
	}
	if(qtde > 0) {
		printf("Quantidade de primos no intervalo [%d,%d] = %d\n", min, max, qtde);
		printf("Soma dos primos no intervalo [%d,%d] = %d\n", min, max, soma);
	} else {
		printf("Não há primos no intervalo [%d,%d]\n", min, max);
	}
	
	system("pause");
	
	return 0;	
}
