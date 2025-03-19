/*atividade 10
10)Usando apenas as funções do arquivo de interface fila.h escreva um procedimento que receba ponteiros para duas filas de números inteiros. 
O procedimento deve concatenar (emendar) os dados da segunda fila na primeira fila. A fila f2 deve permanecer intacta. 

void concatena_fila (Fila *f1, Fila *f2) */

#include "fila.h"

void concatena_fila(Fila *f1, Fila *f2) {
    // Enquanto a fila f2 não estiver vazia, retira um elemento de f2 e insere em f1
    while (!fila_vazia(f2)) {
        int valor = fila_retira(f2); // Retira o elemento de f2
        fila_insere(f1, valor); // Insere o elemento em f1
    }
}
