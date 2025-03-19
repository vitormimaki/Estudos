/*atividade 8
8)Usando apenas o arquivo de interface pilha.h, criado para uma pilha de números reais, 
escreva uma função que receba um ponteiro para uma pilha e retorne uma nova pilha onde cada elemento é a metade do elemento da pilha original. A pilha original não deve ficar vazia. 

Pilha* dividePilha(Pilha *p)*/

#include "pilha.h"

Pilha* dividePilha(Pilha *p) {
    Pilha *nova_pilha = pilha_cria();

    // Enquanto a pilha original não estiver vazia, retira um elemento, divide por 2 e insere na nova pilha
    while (!pilha_vazia(p)) {
        float valor = pilha_retira(p); // Retira um elemento da pilha original
        pilha_insere(nova_pilha, valor / 2.0); // Insere a metade do valor na nova pilha
    }

    return nova_pilha;
}
