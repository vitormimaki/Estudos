#include <stdio.h>
/*
6) Escreva um programa que leia do teclado um vetor de 10 posições. Escreva na tela
quantos valores pares foram armazenados nesse vetor.
*/

int main(){
    int vet[10], i, par = 0;
    for(i = 0; i < 10; i++){
        scanf("%d", &vet[i]);
        if(vet[i] % 2 == 0)
            par++;
    }
    printf("Foi armazenado %d valor(es) par(es) no vetor\n", par);
    return 0;
}