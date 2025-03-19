#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Escreva um programa que leia tr�s n�meros
reais A, B e C que s�o os coeficientes de uma equa��o do 2� grau (A.x2 + B.x + C = 0). Calcule e apresente
na tela as ra�zes dessa equa��o, considerando os tr�s casos poss�veis: Delta maior que zero (duas ra�zes
reais), Delta igual a zero (uma raiz) e Delta menor que zero (n�o h� ra�zes reais).*/

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
