#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	int A[5] = {19, 23, 29, 31, 37};
	
	setlocale(LC_ALL, "portuguese");
	
	printf("Exibi��o Normal:\n");
	
	for(int i = 0; i < 5; i++) {
		printf("A[%d] = %d\n", i, A[i]);
	}
	
	printf("\nExibi��o Invertida:\n");
	
	for(int i = 4; i >= 0; i--) {
		printf("A[%d] = %d\n", i, A[i]);
	}
	
	system("pause");
	return 0;
}
