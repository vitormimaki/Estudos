#include <stdio.h>
/*
5) Faça um programa que leia um vetor de oito posições. Em seguida, leia também dois
valores X e Y quaisquer correspondentes a duas posições no vetor. Seu programa
deverá exibir a soma dos valores encontrados nas respectivas posições X e Y.
*/
int main(){
    int vet[8], x, y, i, soma;
    for(i = 0; i < 8; i++)
        scanf("%d", &vet[i]);
    printf("Digite duas posicoes validas do vetor (0 a 7): ");
    scanf("%d%d", &x, &y);
    soma = vet[x] + vet[y];
    printf("A soma dos valores nas posicoes %d e %d do vetor eh: %d\n", x, y, soma);
    return 0;
}