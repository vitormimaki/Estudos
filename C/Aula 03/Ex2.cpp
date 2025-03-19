#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int num;
	
	printf("Insira um numero: ");
	scanf("%d", &num);
	
	if (num > 0) {
		printf("O numero %d e positivo!\n\n", num);
	} else {
		if (num < 0) {
			printf("O numero %d e negativo!\n\n", num);
		} else {
			printf("O numero %d = 0\n\n", num);
		}
	}
	
	system("pause");
	
	return 0;
}
