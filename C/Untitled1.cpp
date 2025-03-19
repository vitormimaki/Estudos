#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	
	int *P;
	double *X;
	char *C;
	
	setlocale(LC_ALL, "portuguese");
	
	//C = (char *)malloc(sizeof(char)); -> 1
	//X = (double *)malloc(sizeof(double)); -> 8
	//Aloca��o de Mem�ria para P
	P = (int *)malloc(sizeof(int) * 5); //4*5
	P[0] = 19;
	P[1] = 23;
	P[2] = 38;
	P[3] = 41;
	P[4] = 54;
	for(int i = 0; i < 5; i++)
		printf("%d: %d\n", i , P[i]);
	
	//printf("Foi alocada mem�ria para P no endere�o = %d\n", P);
	//printf("O endere�o apontado por P cont�m = %d\n", *P);
	free(C);
	free(X);
	free(P);
	
	printf("\n\nFim do Programa\n");
	system("pause");
	return 0;
}
