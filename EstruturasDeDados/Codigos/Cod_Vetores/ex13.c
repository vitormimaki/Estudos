#include <stdio.h>
/*
13) Faça um programa para ler 10 números diferentes a serem armazenados em um
vetor. Os números deverão ser armazenados no vetor na ordem em que forem lidos, 
sendo que, caso o usuário digite um número que já foi digitado anteriormente, o 
programa deverá pedir a ele para digitar outro número. Note que cada valor
digitado pelo usuário deve ser pesquisado no vetor, verificando se ele existe entre
os números que já foram fornecidos. Exiba na tela o vetor final que foi digitado.
*/
int main(){
    int vetor[10], i, j;
    printf("Digite os 10 numeros: ");
    for(i = 0; i < 10; i++){
        scanf("%d", &vetor[i]);
        for(j = 0; j < i ; j++){
            if(vetor[i] == vetor[j]){
                printf("Digite outro numero diferente de %d: ", vetor[i]);
                i--;
            }
        }
    }
    printf("\n");
    return 0;
}
