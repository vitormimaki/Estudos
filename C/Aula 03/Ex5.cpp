#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que leia tr�s n�meros
reais e informe se eles constituem os lados de um tri�ngulo. Em caso afirmativo, informe se o tri�ngulo
� equil�tero, is�sceles ou escaleno. Para que tr�s n�meros formem um tri�ngulo deve ocorrer que a
soma dos dois lados menores deve ser maior que o lado maior. Para resolver essa quest�o ser� preciso
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
