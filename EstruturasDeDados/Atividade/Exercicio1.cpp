/*exercicio atividade 1
1)Escreva uma função que receba um ponteiro para uma string (*f) e outros 2 caracteres m e p. 
A função deve trocar todas as ocorrências do caractere m pelo caractere p, e retornar o número de vezes que essa troca foi efetuada dentro na string. 
Veja não é trocar a letra ‘m’ pela letra ‘p’. 
int trocaCarac(char *f, char m, char p)*/ 

int trocaCarac(char *f, char m, char p) {
    int count = 0; // Variável para contar o número de substituições

    // Percorre a string até encontrar o caractere nulo
    while (*f != '\0') {
        // Se o caractere atual for igual a m, substitui por p
        if (*f == m) {
            *f = p;
            count++; // Incrementa o contador de substituições
        }
        f++; // Avança para o próximo caractere
    }

    return count;
}
