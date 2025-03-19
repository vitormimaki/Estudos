/*atividade 11
11)Usando apenas o arquivo de interface fila.h, criado para uma fila de n�meros inteiros, escreva uma fun��o que apenas retorne o primeiro elemento da fila recebida, 
mantendo a fila original intacta. 

int primeiroDaFila (Fila *f) */

#include "fila.h"

int primeiroDaFila(Fila *f) {
    // Verifica se a fila est� vazia
    if (fila_vazia(f)) {
        printf("A fila est� vazia.\n");
        return -1; // Retorna um valor inv�lido para indicar que a fila est� vazia
    }

    // Copia o primeiro elemento da fila
    int primeiro_elemento = fila_retira(f);

    // Reinserindo o elemento na fila para mant�-la intacta
    fila_insere(f, primeiro_elemento);

    return primeiro_elemento;
}
