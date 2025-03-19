#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void ExibeVetor(double *pV, int pTam) {
	printf("%4d:", 0);
	for(int i = 0; i < pTam; i++) {
		if(i > 0 && i % 10 == 0) {
			printf("\n");
			printf("%4d:", i);
		}
		printf("%8.1lf", pV[i]);
	}
	printf("\n");
}

int main() {
	
	int n, ipos, ineg;
	double *a;
	double *Pos, *Neg;
	int qtdePos, qtdeNeg;

	srand(time(NULL));
	
	//rand() -> 32767
	
	setlocale(LC_ALL, "portuguese");
	
	do {
		printf("Digite N: ");
		scanf("%d", &n);
	} while (n < 1 || n > 50);
	
	a = (double *)malloc(sizeof(double) * n);
	
	//gde = rand() + 201.0 //0...32767 + 201
	//pqn = rand() % 200 + 1 //1...199
	
	qtdePos = qtdeNeg = 0;
	
	for(int i = 0; i < n; i++) {
		a[i] = (rand() + 201.0) / (rand() % 200 + 1);
		if(rand() % 2 == 0) {
			a[i] = -a[i];
			qtdeNeg++;
		} else {
			qtdePos++;
		}
	}
	
	printf("\nVetor A tem %d elementos\n", n);
	
	ExibeVetor(a, n);
	
	Pos = (double *)malloc(sizeof(double) * qtdePos);
	Neg = (double *)malloc(sizeof(double) * qtdeNeg);
	
	ipos = ineg = 0;
	
	for(int i = 0; i < n; i++){
		if(a[i] >= 0) {
			Pos[ipos] = a[i];
			ipos++;
		} else {
			Neg[ineg] = a[i];
			ineg++;
		}
	}
	
	printf("\nVetor Pos tem %d elementos\n", qtdePos);
	
	ExibeVetor(Pos, qtdePos);
	
	printf("\nVetor Neg tem %d elementos\n", qtdeNeg);
	
	ExibeVetor(Neg, qtdeNeg);
	
	printf("\n");
	system("pause");
	
	return 0;
}
