#include <stdio.h>
#include <conio.h>
#include <math.h>

/*Escreva um programa que leia do teclado um numero
real R. Use o tipo double para R. Calcule e mostre
na tela com tres casas decimais:

a) A area do circulo de raio R
b) O volume de esfera de raio R*/

#define PI 3.1415

int main(void) {
	
	double R;
	float area, volume;
	
	printf("Insira o raio R: ");
	scanf("%lf", &R);
	area = PI*pow(R,2);
	printf("\nA Area do Circulo de raio R e: %.3f", area);
	volume = PI*pow(R, 3)*4/3;
	printf("\nO Volume da Esfera de raio R e: %.3f", volume);
	getch();
	
	return 0;
	
}
