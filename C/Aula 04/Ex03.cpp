#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	
	int x;
	
	setlocale(LC_ALL, "portuguese");
	
	do {
		scanf("%d", &x);
		if (x > 0) {
			printf("%d � Positivo!\n", x);
		} else if (x < 0) {
			printf("%d � Negativo!\n", x);
		}
	} while (x != 0);
	
	system("pause > nul");
	
	return 0;
}
