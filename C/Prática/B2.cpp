#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	
	FILE *Arq;
	int Tam;
	int *V;
	int i, aux;
	bool trocou;
	
	printf("Digite o Tamanho: ");
	scanf("%d", &Tam);
	V = (int *)malloc(sizeof(int) * Tam);
	
	for (i = 0; i < Tam; i++) {
		V[i] = 1 + rand() % (Tam + 1);
	}
	
	printf("Vetor Gerado\n");
	
	Arq = fopen("bsort_gerado.txt", "w");
	
	for(i = 0; i < Tam; i++) {
		fprintf(Arq, "%d\n", V[i]);
	}
	
	fclose(Arq);
	
	//BUBBLE SORT
	trocou = true;
	while (trocou) {
		trocou = false;
		for(i = 0; i < Tam - 1; i++) {
			if(V[i] > V[i+1]) {
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
				trocou = true;
			}
		}
	}
	
	printf("Vetor Ordenado\n");
	
	Arq = fopen("bsort_ordenado.txt", "w");
	
	for(i = 0; i < Tam; i++) {
		fprintf(Arq, "%d\n", V[i]);
	}
	
	fclose(Arq);
	return 0;
}
