#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que leia três números
reais e informe se eles constituem os lados de um triângulo. Em caso afirmativo, informe se o triângulo
é equilátero, isósceles ou escaleno. Para que três números formem um triângulo deve ocorrer que a
soma dos dois lados menores deve ser maior que o lado maior. Para resolver essa questão será preciso
usar os operadores and e or.*/

int main(void) {
	
	int triangulo;
	double n1, n2, n3;
	
	printf("Insira o Primeiro Numero: ");
	scanf("%d", &n1);
	printf("Insira o Segundo Numero: ");
	scanf("%d", &n2);
	printf("Insira o Terceiro Numero: ");
	scanf("%d", &n3);
	
	if (n3 >= n2 && n3 >= n1) {
		if (n2 >= n1) { //n3 >= n2 && n1
			triangulo = (n2 + n1) > n3;
		}
	} else { // n3 < n2 || n3 < n1
		if (n2 >= n1 && n2 >= n3) { //n2 >= n1 && n3  
			triangulo = (n1 + n3) > n2;
		} else {
			if (n1 >= n2 && n1 >= n3) { //n1 >= n2 && n3
				triangulo = (n2 + n3) > n1;
			}
		}
	}
	
	if (!triangulo){
		printf("Os Numeros %d, %d e %d Nao Formam Um Triangulo!\n\n", n1, n2, n3);
	} else { //triangulo == 1
		if (n1 != n2  && n2 != n3 && n1 != n3) {
			printf("Os Numeros formam um Triangulo Escaleno!\n\n");
		} else {
			if (n1 == n2 && n2 == n3) {
				printf("Os Numeros formam um Triangulo Equilatero!\n\n");
			} else {
				printf("Os Numeros formam um Triangulo Isosceles\n\n");
			}
		}
	}
	
	system("pause");
	
	return 0;
}
