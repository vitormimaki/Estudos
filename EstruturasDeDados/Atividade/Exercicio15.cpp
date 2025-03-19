/*atividade 15
15) Dado o typedef de lista encadeada: 

        typedef struct lista{ 

        char nome[20]; 

  char fone[9]; 

           	  struct lista *prox;	 

        }Lista; 

 

    15.a)Crie um procedimento que dado um nome, mostre o fone associado ao nome ou informe que o nome não foi encontrado. 

      void mostraFone(Lista *l, char *nome) */
      
#include <stdio.h>
#include <string.h>

typedef struct lista {
    char nome[20];
    char fone[9];
    struct lista *prox;
} Lista;

void mostraFone(Lista *l, char *nome) {
    // Percorre a lista procurando pelo nome
    while (l != NULL) {
        // Se o nome atual for igual ao nome buscado, mostra o telefone e retorna
        if (strcmp(l->nome, nome) == 0) {
            printf("Telefone de %s: %s\n", nome, l->fone);
            return;
        }
        l = l->prox;
    }
    // Se o nome não foi encontrado, informa que o nome não foi encontrado
    printf("Nome \"%s\" nao encontrado.\n", nome);
}

/*15.b)Crie um procedimento que receba um ponteiro para o primeiro elemento de uma lista já inicializada, um nome e um fone. O procedimento deve inserir os dados no final da lista. 
Para tanto o procedimento deve procurar o final da lista para encadear o novo elemento. 

A função deve ter o seguinte protótipo: 

      void insere_final(Lista *primeiro, char *nome, char *tel) */

