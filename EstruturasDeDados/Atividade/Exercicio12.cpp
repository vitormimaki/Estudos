/*atividade 12
12)Usando apenas o arquivo de interface fila.h, criado para uma fila de números inteiros, escreva uma função que receba ponteiros para duas filas. A função deve criar uma nova fila com o conteúdo intercalado das filas f1 e f2. As filas originais não devem ficar vazias. A função retorna para o programa principal o endereço dessa nova fila.  
Atenção: as filas podem ter tamanhos diferentes!! 

Fila *intercala_fila (Fila *f1, Fila *f2) */

#include "fila.h"

Fila *intercala_fila(Fila *f1, Fila *f2) {
    Fila *nova_fila = fila_cria();

    // Enquanto ambas as filas não estiverem vazias, insere um elemento de cada fila na nova fila
    while (!fila_vazia(f1) || !fila_vazia(f2)) {
        if (!fila_vazia(f1)) {
            int elemento_f1 = fila_retira(f1);
            fila_insere(nova_fila, elemento_f1);
        }
        if (!fila_vazia(f2)) {
            int elemento_f2 = fila_retira(f2);
            fila_insere(nova_fila, elemento_f2);
        }
    }

    return nova_fila;
}
