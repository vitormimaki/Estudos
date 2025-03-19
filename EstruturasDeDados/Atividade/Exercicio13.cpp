/*atividade 13
13)Usando apenas o arquivo de interface fila.h, criado para uma fila de números inteiros, escreva um procedimento que mostre apenas os elementos impares contidos na fila, 
mantendo a fila original intacta. 

void  mostraImpares (Fila *f) */

#include "fila.h"

void mostraImpares(Fila *f) {
    Fila *fila_auxiliar = fila_cria();

    // Percorre a fila e move os elementos ímpares para uma fila auxiliar
    while (!fila_vazia(f)) {
        int elemento = fila_retira(f);
        if (elemento % 2 != 0) {
            printf("%d ", elemento); // Mostra o elemento ímpar
        }
        fila_insere(fila_auxiliar, elemento); // Insere o elemento de volta na fila original
    }

    // Move os elementos de volta para a fila original
    while (!fila_vazia(fila_auxiliar)) {
        fila_insere(f, fila_retira(fila_auxiliar));
    }

    // Libera a fila auxiliar
    fila_libera(fila_auxiliar);
}
