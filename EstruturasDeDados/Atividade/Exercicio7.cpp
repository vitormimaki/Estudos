/*atividade 7
7)Usando apenas o arquivo de interface pilha.h, criado para uma pilha de números reais, escreva um procedimento que receba ponteiros para duas pilhas:p1 e p2. 
A função deve empilhar o conteúdo da pilha p2 sobre a pilha p1, mantendo sua ordem original. A pilha p2 não deve ficar vazia. 

void empilhaPilha(Pilha *p1, Pilha *p2) */
#include "pilha.h"

void empilhaPilha(Pilha *p1, Pilha *p2) {
    // Enquanto a pilha p2 não estiver vazia, retira um elemento de p2 e insere em p1
    while (!pilha_vazia(p2)) {
        float valor = pilha_retira(p2); // Retira o elemento de p2
        pilha_insere(p1, valor); // Insere o elemento em p1
    }
}
