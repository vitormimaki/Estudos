#include <stdio.h>
#include <conio.h>

/*Escreva um programa que leia dois dados inteiros de entrada, calcule e exiba o resultado
conforme a formula a baixo:
R = (3A + 2B)/(A+B)*/

int main(void) {
	
	int A, B;
	float R, num, den;
	
	printf("Insira o Valor para a Variavel A: ");
	scanf("%d", &A);
	printf("Insira o Valor para a Variavel B: ");
	scanf("%d", &B);
	num = (3 * A + 2 * B);
	den = A + B;
	R = num / den;
	printf("O Resultado Seguindo a Formula:\n\n");
	printf("R = 3A + 2B\n");
	printf("    -------\n");
	printf("     A + B\n\n");
	printf("R = %.2f", R);
	getch();
		
	return 0;
	
}
