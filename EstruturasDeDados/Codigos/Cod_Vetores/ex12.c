#include <stdio.h>
/*
12) Faca um programa que leia um vetor de 10 posicoes. 
Verifique se existem valores iguais e os escreva na tela.
*/
void verifica_valoresiguais(int *vetor){
	int i, j;
	for(i = 0; i < 10; i++)
        for(j = i + 1; j < 10; j++)
            if(vetor[i] == vetor[j])
                printf("%d ", vetor[i]);
    printf("\n");
}

int main(){
    int vetor[10], i, j;
    printf("Digite os 10 numeros: ");
    for(i = 0; i < 10; i++)
        scanf("%d", &vetor[i]);
        
    verifica_valoresiguais(vetor);
    
    for(i = 0; i < 10; i++)
        for(j = i + 1; j < 10; j++)
            if(vetor[i] == vetor[j])
                printf("%d ", vetor[i]);
    printf("\n");
    return 0;
}
