#include <stdio.h>
/*
2) Crie um programa que leia do teclado seis valores inteiros e em seguida mostre na
tela os valores lidos na ordem inversa.
*/
int main(){
    int n1, n2, n3, n4, n5, n6;
    scanf("%d%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5, &n6);
    printf("%d %d %d %d %d %d\n", n6, n5, n4, n3, n2, n1);
    return 0;
}