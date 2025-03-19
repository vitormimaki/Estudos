/*atividade 5
5) Crie um procedimento que receba um m�s e informe os amigos que fazem anivers�rio neste m�s. Se no m�s escolhido ningu�m fizer anivers�rio, informe este fato. 

void aniversariantes(Amigo *a, int m�s){ */

#include <stdio.h>
#include <stdbool.h>

// Defini��o da estrutura Amigo
typedef struct {
    char nome[50];
    int mes_aniversario;
} Amigo;

void aniversariantes(Amigo *a, int mes) {
    bool encontrou = false;

    printf("Amigos que fazem anivers�rio no m�s %d:\n", mes);
    for (int i = 0; i < /quantidade de amigos/; i++) {
        if (a[i].mes_aniversario == mes) {
            printf("%s\n", a[i].nome);
            encontrou = true;
        }
    }

    if (!encontrou) {
        printf("Ningu�m faz anivers�rio neste m�s.\n");
    }
}

int main() {
    // Suponha que voc� tenha uma lista de amigos
    Amigo amigos[5] = {
        {"Jo�o", 3},
        {"Maria", 6},
        {"Carlos", 9},
        {"Ana", 3},
        {"Pedro", 12}
    };

    int mes;

    printf("Digite o n�mero do m�s: ");
    scanf("%d", &mes);

    aniversariantes(amigos, mes);

����return�0;
}
