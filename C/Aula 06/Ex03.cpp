#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	int V[15] = {17, 4, 53, 38, 22, 40, 25, 16, 31, 64, 45, 32, 20, 12, 29};
	int a = 1;
	
	setlocale(LC_ALL, "portuguese");
	
	while (a > 0) {
		int achou = 0;
		printf("Escreva o Valor A: ");
		scanf("%d", &a);
		if (a > 0) {
			for(int pos = 0; pos < 15 && achou != 1; pos++) {
				if (V[pos] == a) {
					printf("Valor A = %d encontrado na %d° posição, indice = %d.\n", a, (pos+1), pos);
					achou = 1;
				}
			}
			if (achou == 0)
				printf("Este valor não está no vetor.\n");
		}
	}
	
	system("pause");
	return 0;
}
