#include <stdio.h>
/*
4) Faça um programa que possua um array de nome A que armazene seis números
inteiros. O programa deve executar os seguintes passos:
a) Atribua os seguintes valores a esse array: 1, 0, 5, −2, −5, 7.
b) Armazene em uma variável a soma dos valores das posições A[0], A[1] e A[5]
do array e mostre na tela essa soma.
c) Modifique o array na posição 4, atribuindo a essa posição o valor 100.
d) Mostre na tela cada valor do array A, um em cada linha.
*/

int main(){
    int A[6] = {1,0,5,-2,-5,7}, soma, i;
    soma = A[0] + A[1] + A[5];
    printf("%d\n", soma);
    A[3] = 100;
    for(i = 0; i < 6; i++)
        printf("%d\n", A[i]);
    return 0;
}