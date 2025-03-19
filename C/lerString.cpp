#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	
	int qtd = 0, i;
	char buffer[1000];
	int tam;
	
	printf("Digite a string: ");
	fgets(buffer, sizeof(buffer), stdin);
	
	tam = strlen(buffer) + 1;
	
	char str[tam];
	strncpy(str, buffer, tam);
	
	printf("\n%s", str);
	
	for(i = 0; i < tam; i++) {
		if(str[i] == 'a' || str[i] == 'A') {
			qtd++;
		}
	}
	
	printf("\nOs caracteres 'a' e 'A' ocorrem %d vezes.\n\n", qtd);
	
	system("pause");
	
	return 0;
}
