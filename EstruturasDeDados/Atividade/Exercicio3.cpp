/*atividade 3
3)Escreva um procedimento que receba um ponteiro para uma string. 
A função deve retirar todos os espaços em branco contidos na string (se existirem), modificando (reduzindo) a string original.  

void retira_brancos(char *frase) */

#include <stdio.h>

void retira_brancos(char *frase) {
    // Inicializa um ponteiro para percorrer a string
    char *p = frase;
    // Inicializa um ponteiro para indicar a posição onde será escrito o próximo caractere na string modificada
    char *p_destino = frase;

    // Percorre a string
    while (*p != '\0') {
        // Se o caractere atual não for um espaço em branco, copia-o para a nova posição
        if (*p != ' ') {
            *p_destino = *p;
            p_destino++;
        }
        p++;
    }

    // Adiciona o caractere nulo no final da string para indicar o seu fim
    *p_destino = '\0';
}

int main() {
    // Exemplo de uso
    char frase[] = "Hoje e  sempre  amanha";
    
    printf("Frase original: \"%s\"\n", frase);
    retira_brancos(frase);
    printf("Frase sem espaços em branco: \"%s\"\n", frase);

    return 0;
}
