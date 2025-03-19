/*atividade 8
8)Usando apenas o arquivo de interface pilha.h, criado para uma pilha de n�meros reais, 
escreva uma fun��o que receba um ponteiro para uma pilha e retorne uma nova pilha onde cada elemento � a metade do elemento da pilha original. A pilha original n�o deve ficar vazia. 

Pilha* dividePilha(Pilha *p)*/

#include "pilha.h"

Pilha* dividePilha(Pilha *p) {
    Pilha *nova_pilha = pilha_cria();

    // Enquanto a pilha original n�o estiver vazia, retira um elemento, divide por 2 e insere na nova pilha
    while (!pilha_vazia(p)) {
        float valor = pilha_retira(p); // Retira um elemento da pilha original
        pilha_insere(nova_pilha, valor / 2.0); // Insere a metade do valor na nova pilha
    }

    return�nova_pilha;
}
