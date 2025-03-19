#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void inicio(void) {
	printf("Arthur de Queiroz\n");
	printf("Vitor Aurélio Saccone Mimaki\n");
	printf("Questão 3:\n");
}

int main(void) {
	
	int n;
	
	setlocale(LC_ALL, "portuguese");
	
	inicio();
	
	int nv, qma, qv, cod;
	double precoU, precoV;
	double varejo, atacado;
	double grupoVar = 0, grupoAta = 0;
	int entVar = 0, entAta = 0;
	
	do {
		printf("Insira o Número de Vendas Realizadas (NV): ");
		scanf("%d", &nv);
	} while (nv <= 0);
	
	for(int i = 1; i <= nv; i++) {
		entVar = 0;
		entAta = 0;
		do {
			printf("Venda %d: (Cod) (QV)\n", i);
			scanf("%d %d", &cod, &qv);
			if(cod != 16 && cod != 23 && cod != 27 && cod != 34) {
				printf("\nCódigo Inválido");
			}
		} while (cod != 16 && cod != 23 && cod != 27 && cod != 34);
		switch (cod) {
			case 16:
				qma = 50;
				varejo = 14.35;
				atacado = 12.93;
				break;
			case 23:
				qma = 100;
				varejo = 35.12;
				atacado = 29.85;
				break;
			case 27:
				qma = 70;
				varejo = 19.35;
				atacado = 16.76;
				break;
			default:
				qma = 40;
				varejo = 63.40;
				atacado = 58.25;
		}
		if (qv < qma) {
			precoU = varejo;
			entVar = 1;
		} else {
			precoU = atacado;
			entAta = 1;
		}
		precoV = precoU * qv;
		if (entVar == 1) {
			grupoVar += precoV;
		} else if (entAta == 1){
			grupoAta += precoV;
		}
	}
	
	printf("\n\nTotal de Vendas do Grupo Varejo: R$%.2lf\n", grupoVar);
	printf("\nTotal de Vendas do Grupo Atacado: R$%.2lf\n", grupoAta);
	
	printf("\nVendas Totais: R$%.2lf\n", (grupoVar + grupoAta));
	
	system("pause");
	
	return 0;
}
