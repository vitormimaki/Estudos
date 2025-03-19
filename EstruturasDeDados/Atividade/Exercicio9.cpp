/*atividade 9
9)Usando apenas o arquivo de interface pilha.h, criado para uma pilha de números reais, escreva uma função que receba o ponteiro para uma pilha pi. 
A função deve retornar o elemento que está na base da pilha, mantendo a pilha intacta. 

float base(Pilha *pi) */

#include "pilha.h"

float base(Pilha *pi) {
    Pilha *auxiliar = pilha_cria();
    float elemento_base;

    // Move todos os elementos de pi para a pilha auxiliar
    while (!pilha_vazia(pi)) {
        float valor = pilha_retira(pi);
        pilha_insere(auxiliar, valor);
    }

    // O elemento que está na base da pilha original é o topo da pilha auxiliar
    elemento_base = pilha_retira(auxiliar);

    // Move todos os elementos de volta para a pilha original
    while (!pilha_vazia(auxiliar)) {
        float valor = pilha_retira(auxiliar);
        pilha_insere(pi, valor);
    }

    // Libera a pilha auxiliar
    pilha_libera(auxiliar);

    // Retorna o elemento que estava na base da pilha original
    return elemento_base;
}
