/*atividade 11
11)Usando apenas o arquivo de interface fila.h, criado para uma fila de números inteiros, escreva uma função que apenas retorne o primeiro elemento da fila recebida, 
mantendo a fila original intacta. 

int primeiroDaFila (Fila *f) */

#include "fila.h"

int primeiroDaFila(Fila *f) {
    // Verifica se a fila está vazia
    if (fila_vazia(f)) {
        printf("A fila está vazia.\n");
        return -1; // Retorna um valor inválido para indicar que a fila está vazia
    }

    // Copia o primeiro elemento da fila
    int primeiro_elemento = fila_retira(f);

    // Reinserindo o elemento na fila para mantê-la intacta
    fila_insere(f, primeiro_elemento);

    return primeiro_elemento;
}
