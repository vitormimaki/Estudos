#include <stdio.h>

int busca (int a[], int k, int n, int x)
{
    if (k == n) 
		return -1;
    if (a[k] == x) 
		return k;
    return busca (a, k + 1, n, x);
}

int main()
{
	//int tabela[] = {2, 4, 8, 0, -1, 7, 23, 12, 18, 11};
    int tabela[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int n = 10, zz, r;
    zz = 23;
    // procura o valor zz na tabela
    r = busca(tabela, 0, n, zz);
    printf("\nprocura %d resultado = %d", zz, r);
    zz = 14;
    // procura o valor zz na tabela
    r = busca(tabela, 0, n, zz);
    printf("\nprocura %d resultado = %d", zz, r);
}
