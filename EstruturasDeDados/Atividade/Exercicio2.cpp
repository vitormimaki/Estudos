/*atividade 2
2)Escreva um procedimento que receba um ponteiro para uma string (palavra), e informe(escreva) se a palavra é um palíndromo. (Palíndromo é uma palavra que permanece igual se escrita ao contrário). 
Caso use uma string auxiliar, para resolver o problema, note que o tamanho desta string não deve ser presumido, mas calculado!!!  

Exemplos: arara, osso, asa, etc... são palíndromos 

void palindromo(char *palavra)  */

#include <stdio.h>

// Função para calcular o comprimento de uma string
int comprimento(char *palavra) {
    int len = 0;
    while (*palavra != '\0') {
        len++;
        palavra++;
    }
    return len;
}

// Procedimento para verificar se a palavra é um palíndromo
void palindromo(char *palavra) {
    int len = comprimento(palavra); // Calcula o comprimento da palavra

    // Aloca memória para a string reversa
    char reversa[len + 1]; // +1 para o caractere nulo no final
    reversa[len] = '\0'; // Garante que a string reversa termine com o caractere nulo

    // Preenche a string reversa com os caracteres da palavra na ordem inversa
    for (int i = 0; i < len; i++) {
        reversa[i] = palavra[len - 1 - i];
    }

    // Verifica se a palavra original é igual à palavra reversa
    int igual = 1; // Assume que são iguais
    for (int i = 0; i < len; i++) {
        if (palavra[i] != reversa[i]) {
            igual = 0; // Se encontrar caracteres diferentes, são diferentes
            break;
        }
    }

    // Se forem iguais, é um palíndromo
    if (igual == 1) {
        printf("%s é um palíndromo.\n", palavra);
    } else {
        printf("%s não é um palíndromo.\n", palavra);
    }
}

int main() {
    // Exemplo de uso
    char palavra1[] = "arara";
    char palavra2[] = "casa";
    
    palindromo(palavra1); // Deve imprimir: arara é um palíndromo.
    palindromo(palavra2); // Deve imprimir: casa não é um palíndromo.
    
    return 0;
}
