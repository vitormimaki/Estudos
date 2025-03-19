#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	
	int num, sumN = 0, sumP = 0;
	
	setlocale(LC_ALL, "portuguese");
	
	do {
		scanf("%d", &num);
		if (num > 0) {
			sumP += num;
		} else if (num < 0) {
			sumN += num;
		}
	} while (num != 0);
	
	printf("\nTotal dos positivos = %d", sumP);
	printf("\nTotal dos negativos = %d", sumN);
	system("pause > nul");
	
	return 0;
}
