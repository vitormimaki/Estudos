/*atividade 2
2)Escreva um procedimento que receba um ponteiro para uma string (palavra), e informe(escreva) se a palavra � um pal�ndromo. (Pal�ndromo � uma palavra que permanece igual se escrita ao contr�rio). 
Caso use uma string auxiliar, para resolver o problema, note que o tamanho desta string n�o deve ser presumido, mas calculado!!!  

Exemplos: arara, osso, asa, etc... s�o pal�ndromos 

void palindromo(char *palavra)  */

#include <stdio.h>

// Fun��o para calcular o comprimento de uma string
int comprimento(char *palavra) {
    int len = 0;
    while (*palavra != '\0') {
        len++;
        palavra++;
    }
    return len;
}

// Procedimento para verificar se a palavra � um pal�ndromo
void palindromo(char *palavra) {
    int len = comprimento(palavra); // Calcula o comprimento da palavra

    // Aloca mem�ria para a string reversa
    char reversa[len + 1]; // +1 para o caractere nulo no final
    reversa[len] = '\0'; // Garante que a string reversa termine com o caractere nulo

    // Preenche a string reversa com os caracteres da palavra na ordem inversa
    for (int i = 0; i < len; i++) {
        reversa[i] = palavra[len - 1 - i];
    }

    // Verifica se a palavra original � igual � palavra reversa
    int igual = 1; // Assume que s�o iguais
    for (int i = 0; i < len; i++) {
        if (palavra[i] != reversa[i]) {
            igual = 0; // Se encontrar caracteres diferentes, s�o diferentes
            break;
        }
    }

    // Se forem iguais, � um pal�ndromo
    if (igual == 1) {
        printf("%s � um pal�ndromo.\n", palavra);
    } else {
        printf("%s n�o � um pal�ndromo.\n", palavra);
    }
}

int main() {
    // Exemplo de uso
    char palavra1[] = "arara";
    char palavra2[] = "casa";
    
    palindromo(palavra1); // Deve imprimir: arara � um pal�ndromo.
    palindromo(palavra2); // Deve imprimir: casa n�o � um pal�ndromo.
    
����return�0;
}
