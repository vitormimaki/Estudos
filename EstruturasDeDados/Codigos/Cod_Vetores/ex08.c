#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
8) Faça um programa que preencha um vetor com 10 números reais. Em seguida,
calcule e mostre na tela a quantidade de números negativos e a soma dos números
positivos desse vetor.
*/

/*
A função que gera números aleatórios em C é a rand().
Ela gera números entre 0 e RAND_MAX, onde esse RAND_MAX é um valor 
que pode variar de máquina pra máquina.
Pra usar a função rand(), temos que adicionar a biblioteca time.h e 
para saber o valor de RAND_MAX, temos que usar a função stdlib.h.
*/
/*
A seqüência gerada é sempre a mesma. Para mudar isso, vamos alimentar a
função rand() com uma semente, com um número, que é o tempo atual.
Assim, toda vez que rodarmos o programa, a rand() pega um número de 
tempo diferente e gera uma seqüencia diferente.
Para fazer isso, basta usar a função srand(), que será responsável por 
alimentar a rand(). Fazemos isso adicionando o comando: srand( (unsigned)time(NULL) ); antes da rand().
E agora nosso aplicativo em C gera uma seqüencia diferente toda vez que rodamos.
*/

int main(){
    float vetor[10], soma = 0;
    int i, negativos = 0;
    srand(time(NULL));

    for(i = 0; i < 10; i++)
        vetor[i] = ((rand() % (RAND_MAX)) - (rand() % RAND_MAX)) / (float)rand();
    
    for(i = 0; i < 10; i++){
        if(vetor[i] > 0)
            soma += vetor[i];
        else
            negativos++;
    }
    printf("O vetor possui %d numeros negativos e\na soma dos numeros " 
    "positivos eh %0.3f\n", negativos, soma);    
    return 0;
}