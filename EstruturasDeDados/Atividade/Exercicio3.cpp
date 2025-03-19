/*atividade 3
3)Escreva um procedimento que receba um ponteiro para uma string. 
A fun��o deve retirar todos os espa�os em branco contidos na string (se existirem), modificando (reduzindo) a string original.  

void retira_brancos(char *frase) */

#include <stdio.h>

void retira_brancos(char *frase) {
    // Inicializa um ponteiro para percorrer a string
    char *p = frase;
    // Inicializa um ponteiro para indicar a posi��o onde ser� escrito o pr�ximo caractere na string modificada
    char *p_destino = frase;

    // Percorre a string
    while (*p != '\0') {
        // Se o caractere atual n�o for um espa�o em branco, copia-o para a nova posi��o
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
    printf("Frase sem espa�os em branco: \"%s\"\n", frase);

����return�0;
}
