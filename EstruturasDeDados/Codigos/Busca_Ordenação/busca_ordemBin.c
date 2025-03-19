/*
quando a tabela esta ordenada, fazemos busca binaria.
A versao busca binaria eh mais interessante. Comparamos com o elemento
medio da tabela. Se for igual a busca termina, se for maior, verificamos
o meio da tabela. Se for maior, fazemos a busca na tabela superior, senao
na tabela inferior. A busca termina quando a tabela tiver zero elementos.
*/
#include <stdio.h>

// procura x no vetor a, devolvendo o indice do elemento igual ou -1
int busca_binaria (int a[], int inicio, int final, int x)
{
    int k;

    if (inicio > final) 
		return -1;
    k = (inicio + final) / 2;
    if (a[k] == x) 
		return k;
    if (a[k] > x) 
		return busca_binaria(a, inicio, k - 1, x);
    if (a[k] < x) 
		return busca_binaria(a, k + 1, final, x);
}

int main()
{
    int tabela[] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int n = 10, zz, r;
    zz = 23;
    // procura o valor zz na tabela
    r = busca_binaria(tabela, 0, n, zz);
    printf("\nprocura %d resultado = %d", zz, r);
    zz = 26;
    // procura o valor zz na tabela
    r = busca_binaria(tabela, 0, n, zz);
    printf("\nprocura %d resultado = %d", zz, r);
}
