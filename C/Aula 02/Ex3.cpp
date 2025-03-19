#include <stdio.h>
#include <conio.h>

/*Escreva um programa para calcular o salario bruto de um
profissional que recebe por hora, sabendo que ele ganha R$14,25/h
e trabalhou 163 horas normais e 20 horas extras (pagam o dobro).
Nao use valores fixos no programa. Ao inves disso faça a leitura
dos dados de entrada em variaveis para o valor hora, o numero de horas
normais e o numero de horas extras.*/

int main(void) {
	
	float valor_h, total;
	int horas_n, horas_ex;
	
	printf("Insira o Valor do Salario por Hora: ");
	scanf("%f", &valor_h);
	printf("Insira a Quantidade de Horas Normais Trabalhadas: ");
	scanf("%d", &horas_n);
	printf("Insira a Quantidade de Horas Extras Trabalhadas: ");
	scanf("%d", &horas_ex);
	total = (horas_n * valor_h) + (horas_ex * valor_h * 2);
	printf("O Salario Bruto do Profissional sera de: %.2f", total);
	getch();
	
	return 0;
	
}
