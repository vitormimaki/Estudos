#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	
	setlocale(LC_ALL, "portuguese");
	
	printf("Arthur de Queiroz\n");
	printf("Vitor Aur�lio Saccone Mimaki\n");
	printf("Quest�o 3\n");
	
	int min, max, soma, qtde, i, j, primo;
	
	do {
		printf("\nEscolha um N�mero M�nimo para o Intervalo: ");
		scanf("%d", &min);
		if (min <= 1) {
			printf("\nO n�mero deve ser maior que 1");
		}
	} while (min <= 1);
	
	do {
		printf("\nEscolha um N�mero M�ximo para o Intervalo: ");
		scanf("%d", &max);
		if (max <= min) {
			printf("\nO N�mero deve ser maior que o M�nimo");
		}
	} while (max <= min);
	
	soma = 0;
	qtde = 0;
	
	printf("Min = %d e M�x = %d\n", min, max);
	
	//Primo = S� divisivel por 1 e por ele mesmo
	
	for(i = min; i <= max; i++) { //Come�a do M�nimo
		primo = 1; //N�o sei se � primo, mas roda o la�o ae
		for(j = 2; j < i && primo == 1; j++) { //Conta de j at� i
			if(i % j == 0) { //Se h� divisores
				primo = 0; //N�o � Primo
			} else { //Se n�o h� divisores
				primo = 1; //� primo
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
		printf("N�o h� primos no intervalo [%d,%d]\n", min, max);
	}
	
	system("pause");
	
	return 0;	
}
