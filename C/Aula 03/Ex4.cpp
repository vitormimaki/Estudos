#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Escreva um programa que leia três números
reais A, B e C que são os coeficientes de uma equação do 2º grau (A.x2 + B.x + C = 0). Calcule e apresente
na tela as raízes dessa equação, considerando os três casos possíveis: Delta maior que zero (duas raízes
reais), Delta igual a zero (uma raiz) e Delta menor que zero (não há raízes reais).*/

int main(void) {
	
	double a, b, c, x1, x2, delta;
	
	printf("Insira o Valor de A: ");
	scanf("%lf", &a);
	printf("Insira o Valor de B: ");
	scanf("%lf", &b);
	printf("Insira o Valor de C: ");
	scanf("%lf", &c);
	
	printf("\n%.2lf*X^2 + %.2lf*X + %.2lf = 0\n", a, b, c);
	
	delta = (pow(b, 2) - 4 * a * c);
	x1 = (-b + sqrt(delta))/(2*a);
	x2 = (-b - sqrt(delta))/(2*a);
	
	if (delta < 0) {
		printf("\nNumero Complexo, nao ha raiz real.\n\n");
	} else {
		printf("\nDelta = %.2lf\n", delta);
		printf("\nX1 = %.2lf", x1);
		printf("\nX2 = %.2lf\n\n", x2);
	}
	 
	system("pause");
	
	return 0;
}
