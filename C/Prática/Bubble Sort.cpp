#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	
	//int V[8] = {16, 8, 19, 4, 23, 12, 7, 10};
	int Tam = 100;
	int V[Tam];
	int i, aux;
	
	for (i = 0; i < Tam; i++) {
		V[i] = rand() % (Tam + 1);
	}
	
	bool trocou;
	
	printf("Vetor Original\n\n");
	for(i = 0; i < Tam; i++) {
		printf("%d  ", V[i]);
	}
	
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
	
	printf("\n\nVetor Ordenado\n\n");
	for(i = 0; i < Tam; i++) {
		printf("%d  ", V[i]);
	}
	
	printf("\n");
	system("pause");
	return 0;
}
