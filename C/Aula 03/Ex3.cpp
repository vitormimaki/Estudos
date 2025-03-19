#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	double peso;
	
	printf("Peso fornecido: ");
	scanf("%lf", &peso);
	
	if (peso < 65) {
		printf("Este lutador pesa %.2lf kg e se enquadra na categoria Pena\n\n", peso);
	} else { // >= 65
		if (peso < 72) {
			printf("Este lutador pesa %.2lf kg e se enquadra na categoria Leve\n\n", peso);
		} else { // >= 72
			if (peso < 79) {
				printf("Este lutador pesa %.2lf kg e se enquadra na categoria Ligeiro\n\n", peso);
			} else { // >= 79
				if (peso < 86) {
					printf("Este lutador pesa %.2lf kg e se enquadra na categoria Meio Medio\n\n", peso);
				} else { // >= 86
					if (peso < 93) {
						printf("Este lutador pesa %.2lf kg e se enquadra na categoria Medio\n\n", peso);
					} else { // >= 93
						if (peso < 100) {
							printf("Este lutador pesa %.2lf kg e se enquadra na categoria Meio Pesado\n\n", peso);
						} else { // >= 100
							printf("Este lutador pesa %.2lf kg e se enquadra na categoria Pesado\n\n", peso);
						}
					}
				}
			}
		}
	}
	
	
	system("pause");
	
	return 0;
}
