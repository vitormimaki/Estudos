#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(void) {
	
	setlocale(LC_ALL, "portuguese");
	
	printf("Arthur de Queiroz\n");
	printf("Vitor Aurélio Saccone Mimaki\n");
	printf("Questão 4\n");
	
	int sort, min, max, i;
	int *N;
	int tentativas, acertou, diferenca;
	
	srand(time(NULL));
	
	max = min = 0;
	
	while(!(max > min + 100)) {
		system("cls");
		inicio();
		printf("\nInsira um Valor Mínimo para o Intervalo de Sorteio: ");
		scanf("%d", &min);
		printf("\nInsira um Valor Máximo para o Intervalo de Sorteio: ");
		scanf("%d", &max);
		if(!(max > min + 100)) {
			printf("\nO Valor Máximo deve ser Maior que Min + 100");
		}
	}
	
	do {
		printf("Insira um número a ser adivinhado: ");
		scanf("%d", &sort);
	} while (sort < min || sort > max)
	
	tentativas = 0;
	acertou = 0;
	diferenca = 0;
	
	N = NULL;
	
	for(i = 0; acertou == 0; i++) {
		N = (int *)realloc(N, sizeof(int) * (i+1));
		printf("Palpite %d: ", i+1);
		scanf("%d", &N[i]);
		if(acertou == 0) {
			printf("\terrado: seu palpite deve ser menor\n");
		} else {
			printf("\tAcertou!!!\n");
			acertou = 1;
		}
	}
	
	printf("Resultado:\nforam %d palpites até você acertar\n", i);
	printf("e os seus palpites foram esses: ");
	
	for(int j = 0; j < i; j++) {
		if (j == i - 1) {
			printf("%d", N[j]);
		} else {
			printf("%d, ", N[j]);
		}
	}
	
	system("pause");
	
	return 0;
}
