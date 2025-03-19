#include <stdio.h>
/*
10) Faça um programa que preencha um vetor de tamanho 100 com os 100 primeiros
números naturais que não são múltiplos de 7. Ao final, imprima esse vetor na tela.
*/

int main(){
    int vetor[100], num = 1, i;
    for(i = 0; i != 100; num++){
        if(num % 7 != 0){
            vetor[i] = num;
            i++;
        }
    }
    for(i = 0; i < 100; i++)
        printf("%d ", vetor[i]);
    printf("\n");
    return 0;
}