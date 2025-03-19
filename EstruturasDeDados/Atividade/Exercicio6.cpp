/*atividade 6
6)Crie uma função que retorne a quantidade de amigos que nasceram em um determinado ano. 

int nascidos (Amigo *a, int ano){ 
Os arquivos da interface pilha.h e fila.h contem, respectivamente, as seguintes funções: 

<pilha.h> 

 

Pilha *pilha_cria(void); 

void pilha_insere(Pilha *p,          float v); 

float pilha_retira(Pilha *p); 

int pilha_vazia(Pilha *p); 

void pilha_libera(Pilha *p); 

<fila.h> 

 

Fila *fila_cria(void); 

void fila_insere(Fila *f,       int v); 

int fila_retira(Fila *f); 

int fila_vazia(Fila *f); 

void fila_libera(Fila *f); 

 

Use tão somente as funções apresentadas! */

#include <stdio.h>
#include <stdbool.h>

// Definição da estrutura Amigo
typedef struct {
    char nome[50];
    int ano_nascimento;
} Amigo;

int nascidos(Amigo *a, int ano) {
    int quantidade = 0;

    for (int i = 0; i < /quantidade de amigos/; i++) {
        if (a[i].ano_nascimento == ano) {
            quantidade++;
        }
    }

    return quantidade;
}

int main() {
    // Suponha que você tenha uma lista de amigos
    Amigo amigos[5] = {
        {"João", 1990},
        {"Maria", 1985},
        {"Carlos", 1990},
        {"Ana", 1995},
        {"Pedro", 1985}
    };

    int ano;

    printf("Digite o ano: ");
    scanf("%d", &ano);

    int quantidade = nascidos(amigos, ano);
    printf("Quantidade de amigos nascidos em %d: %d\n", ano, quantidade);

    return 0;
}
