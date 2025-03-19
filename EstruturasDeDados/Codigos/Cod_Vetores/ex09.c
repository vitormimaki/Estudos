#include <stdio.h>
/*
9) Faca um programa que rec
eba do usuario 
dois arrays, A e B, com 10 números inteiros cada. 
Crie um novo array C calculando C = A - B. 
Mostre na tela os dados do array C.
*/

int main(){
    int A[10], B[10], C[10], i;
    printf("Digite os 10 valores do vetor A e do vetor B: ");
    //preenche vetor A
	for(i = 0; i < 10; i++) 
        scanf("%d", &A[i]);
    //preenche vetor B
    for(i = 0; i < 10; i++)
        scanf("%d", &B[i]);
        
    for(i = 0; i < 10; i++){
        C[i] = A[i] - B[i];
        printf("%d,", C[i]);
    }
    printf("\n");
    return 0;
}
