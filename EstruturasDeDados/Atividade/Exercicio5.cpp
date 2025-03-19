/*atividade 5
5) Crie um procedimento que receba um mês e informe os amigos que fazem aniversário neste mês. Se no mês escolhido ninguém fizer aniversário, informe este fato. 

void aniversariantes(Amigo *a, int mês){ */

#include <stdio.h>
#include <stdbool.h>

// Definição da estrutura Amigo
typedef struct {
    char nome[50];
    int mes_aniversario;
} Amigo;

void aniversariantes(Amigo *a, int mes) {
    bool encontrou = false;

    printf("Amigos que fazem aniversário no mês %d:\n", mes);
    for (int i = 0; i < /quantidade de amigos/; i++) {
        if (a[i].mes_aniversario == mes) {
            printf("%s\n", a[i].nome);
            encontrou = true;
        }
    }

    if (!encontrou) {
        printf("Ninguém faz aniversário neste mês.\n");
    }
}

int main() {
    // Suponha que você tenha uma lista de amigos
    Amigo amigos[5] = {
        {"João", 3},
        {"Maria", 6},
        {"Carlos", 9},
        {"Ana", 3},
        {"Pedro", 12}
    };

    int mes;

    printf("Digite o número do mês: ");
    scanf("%d", &mes);

    aniversariantes(amigos, mes);

    return 0;
}
