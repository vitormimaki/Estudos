#include <stdio.h>
#include <conio.h>

/*  Escreva um programa que leia as medidas de 
base e altura de um tri�ngulo e calcule sua �rea. Use vari�veis que comportem n�meros reais, tanto 
para os dados de entrada como para o resultado. */

int main (void) {
	
	float base, altura, area;
	
	printf("Insira o Valor da Base do Triangulo: ");
	scanf("%f", &base);
	printf("Insira o Valor da Altura do Triangulo: ");
	scanf("%f", &altura);
	area = (base * altura) / 2;
	printf("A Area do Triangulo e: %.2f", area);
	
	getch();
	
	return 0;
}
