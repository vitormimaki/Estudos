#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	int A[10] = {0}, x = 1, cont = 1;
	
	setlocale(LC_ALL, "portuguese");
	
	while (x != 0 && A[9] == 0) {
		printf("Insira o %d° valor: ", cont);
		scanf("%d", &x);
		if (x != 0)
			A[cont-1] = x;
		cont++;
	}
	
	for(int i = 0; i < 10; i++) {
		printf("A[%d] = %d\n", i, A[i]);
	}
	
	system("pause");
	return 0;
}
