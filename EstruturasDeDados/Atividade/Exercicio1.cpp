/*exercicio atividade 1
1)Escreva uma fun��o que receba um ponteiro para uma string (*f) e outros 2 caracteres m e p. 
A fun��o deve trocar todas as ocorr�ncias do caractere m pelo caractere p, e retornar o n�mero de vezes que essa troca foi efetuada dentro na string. 
Veja n�o � trocar a letra �m� pela letra �p�. 
int trocaCarac(char *f, char m, char p)*/ 

int trocaCarac(char *f, char m, char p) {
    int count = 0; // Vari�vel para contar o n�mero de substitui��es

    // Percorre a string at� encontrar o caractere nulo
    while (*f != '\0') {
        // Se o caractere atual for igual a m, substitui por p
        if (*f == m) {
            *f = p;
            count++; // Incrementa o contador de substitui��es
        }
        f++; // Avan�a para o pr�ximo caractere
    }

   �return�count;
}
