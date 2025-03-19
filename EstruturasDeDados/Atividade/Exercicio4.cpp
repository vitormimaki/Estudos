/*atividade 4
4)Escreva um procedimento que receba um ponteiro para uma string p e mostre(imprima)o número de ocorrências de cada letra dentro da palavra. 

Exemplo: arara deve mostrar a=3 e r=2 

         sapato deve mostrar s=1, a=2, t=1 e o=1    

     void contaLetras(char *p) 

 

TIPOS ESTRUTURADOS 

Crie o seguinte tipo estruturado: 

typedef struct { 

  nome char[31], 

  dia int, 

  mes int, 

  ano int}Amigo;  

Armazene informações de 10 amigos em um vetor desse tipo estruturado. */

#include <stdio.h>

void contaLetras(char *p) {
    // Inicializa um array de contagem para cada letra do alfabeto
    int contagem[26] = {0}; // 26 letras do alfabeto

    // Percorre a string
    while (*p != '\0') {
        // Se o caractere atual for uma letra minúscula, incrementa a contagem correspondente
        if (*p >= 'a' && *p <= 'z') {
            contagem[*p - 'a']++;
        }
        // Se o caractere atual for uma letra maiúscula, incrementa a contagem correspondente
        else if (*p >= 'A' && *p <= 'Z') {
            contagem[*p - 'A']++;
        }
        p++; // Avança para o próximo caractere
    }

    // Imprime o resultado
    for (int i = 0; i < 26; i++) {
        // Verifica se a letra foi encontrada ao menos uma vez
        if (contagem[i] > 0) {
            printf("%c=%d ", 'a' + i, contagem[i]);
        }
    }
    printf("\n");
}

int main() {
    // Exemplos de uso
    char palavra1[] = "arara";
    char palavra2[] = "sapato";

    printf("Contagem de letras em \"%s\": ", palavra1);
    contaLetras(palavra1);

    printf("Contagem de letras em \"%s\": ", palavra2);
    contaLetras(palavra2);

    return 0;
}
