#include <stdio.h>
/*
3) Faça um programa que leia cinco valores e os armazene em um vetor. Em seguida,
mostre todos os valores lidos juntamente com a média dos valores.
*/
int main(){
    int i, vetor[5];
    float media = 0;
    for(i = 0; i < 5; i++)
        scanf("%d", &vetor[i]);
    for(i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
        media += vetor[i];
    }
    printf("\nMedia: %f\n", media/5);
    return 0;
}
