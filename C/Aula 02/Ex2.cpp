#include <stdio.h>
#include <conio.h>

/*Escreva um programa que leia quatro numeros inteiros A,B,C e D.
Calcule e mostre na tela a soma e a media desses quatro numeros.
Fique atento com o tipo da variavel a ser usada para calculo da
media, pois o resultado pode ser um numero real.*/

int main(void) {
	
	int A, B, C, D;
	float soma, media;
	
	printf("Insira um Valor para A: ");
	scanf("%d", &A);
	printf("Insira um Valor para B: ");
	scanf("%d", &B);
	printf("Insira um Valor para C: ");
	scanf("%d", &C);
	printf("Insira um Valor para D: ");
	scanf("%d", &D);
	soma = A+B+C+D;
	media = soma/4;
	printf("\nA Soma das Variaveis e: %.0f", soma);
	printf("\nA Media dos Valores e: %.2f", media);
	getch();
	
	return 0;
	
}
