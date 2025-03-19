#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
	
	int *N, min, max, A;
	
	setlocale(LC_ALL, "portuguese");
	
	do {
		printf("Insira um N�mero M�nimo: ");
		scanf("%d", &min);
		if(min < 1) {
			system("cls");
			printf("O N�mero M�nimo deve Ser Maior que 1.\n");
		}
	} while (min < 1);
	
	do {
		printf("Insira um N�mero M�ximo: ");
		scanf("%d", &max);
		if(max < min) {
			system("cls");
			printf("O N�mero M�ximo deve Ser Maior que o M�nimo.\n");
		}
	} while (max < min);
	
	printf("Informe um Valor A: ");
	scanf("%d", &A);
	
	int *v;
	
	v = (int *)malloc(sizeof(int) * (max - min + 1));
	
	for(int i = 0; min <= max; min++) {
		if(min % A == 0) {
			v[i] = min;
			printf("v[%d] = %d\n", i, v[i]);
			i++;
		}
	}
	
	free(v);
	
	system("pause");
	return 0;
}
