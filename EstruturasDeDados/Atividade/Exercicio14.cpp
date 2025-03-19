/*atividade 14
14)Dada uma lista simplesmente encadeada de valores inteiros como se segue: 

typedef struct lista{ 

          int numero; 

    struct lista *next; 

     }Lista; 

 

 

14.a) Crie uma função que retorne a soma dos números contidos na lista: 

int somaNumeros (Lista *L) 

 

   14.b)Crie uma função que retorne o maior número contido na lista: 

 

int maiorNumero (Lista *Li) 

 

   14.c)Crie uma função que retorne uma nova lista contendo apenas os valores (itens) pares da lista: 

 

Lista *lista_pares(Lista *L1) */

#include <stdlib.h>

typedef struct lista {
    int numero;
    struct lista *next;
} Lista;

Lista *lista_pares(Lista *L1) {
    Lista *nova_lista = NULL; // Inicializa a nova lista como vazia
    Lista *ultimo = NULL; // Ponteiro para o último nó da nova lista

    // Percorre a lista original
    Lista *atual = L1;
    while (atual != NULL) {
        // Se o número atual for par, adiciona à nova lista
        if (atual->numero % 2 == 0) {
            Lista *novo_no = (Lista *)malloc(sizeof(Lista));
            novo_no->numero = atual->numero;
            novo_no->next = NULL;

            // Se for o primeiro elemento da nova lista
            if (nova_lista == NULL) {
                nova_lista = novo_no;
                ultimo = novo_no;
            } else {
                // Se não for o primeiro elemento, adiciona ao final da lista
                ultimo->next = novo_no;
                ultimo = novo_no;
            }
        }
        atual = atual->next;
    }

    return nova_lista;
}
