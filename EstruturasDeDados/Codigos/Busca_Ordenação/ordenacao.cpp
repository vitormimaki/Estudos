#include <stdio.h>
#include <stdlib.h>

void imprimir (int X[], int n) {
  int i;
  printf("(");
  for (i=0; i<n; i++) printf("%3d ", X[i]);
  printf(")\n");
}

void imprimirCaractere (char X[], int n) {
  int i;
  printf("(");
  for (i=0; i<n; i++) 
  	printf("%c ", X[i]);
  printf(")\n");
}


//###################################################################################################
// ordenação por bolha
//###################################################################################################

void bubblesort(int v[], int tam) {
    int i, aux,trocou;
    do {
        tam--;
        trocou = 0; //usado para otimizar o algoritmo
        for(i = 0; i < tam; i++)
              if(v[i] > v[i + 1]) {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                trocou = 1;
            }
    } while(trocou);
} 

void bubblesortCaractere(char v[], int tam) {
    int i, aux, trocou;
    //char aux[];
    do {
        tam--;
        trocou = 0; //usado para otimizar o algoritmo
        for(i = 0; i < tam; i++)
              if(v[i] > v[i + 1]) {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                trocou = 1;
            }
        imprimirCaractere(v, 6);
    } while(trocou);
} 

//###################################################################################################
// ordenação por seleção
//###################################################################################################

void selection_sort(int num[], int tam) {
    int i, j, min;
    for (i = 0; i < (tam-1); i++) {
        min = i;
        for (j = (i+1); j < tam; j++) {
            if(num[j] < num[min]) {
                      min = j;
            }
        }
        if (i != min) {
            int swap = num[i];
            num[i] = num[min];
            num[min] = swap;
        }
    }
}

//###################################################################################################
// ordenação por inserção
//###################################################################################################

void insertionSort(int v[], int n) {
    int i, j, chave;
    for(j=1; j<n; j++) {
        chave = v[j];
        i = j-1;
        while(i >= 0 && v[i] > chave){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = chave;
    }
}

//###################################################################################################
// ordenação por contagem
//###################################################################################################

void ordena_por_contagem(int vet[], int ord[], int n){
    int i,j,p;
    //determinar a posição de cada elemento do vetor
    //quando ordenado
    for(i=0;i<n;i++){
        p=0;
        for(j=0;j<n;j++)
            if (vet[i]>vet[j]) p++;
        ord[p]=vet[i];
    }
}

//###################################################################################################
// count sort - com numeros repetidos
//###################################################################################################
void ordena_por_contagemrepetidos(int vet[], int ord[], int n){
    int i,j,p;
    //determinar a posição de cada elemento do vetor
    //quando ordenado
    for(i=0;i<n;i++){
        p=0;
        for(j=0;j<n;j++)
            if (vet[i]>vet[j]) p++;

        ord[p]=vet[i];
    }
    imprimir(ord, 8);
}

//###################################################################################################
// quicksort
//###################################################################################################
void quicksort (int v[], int primeiro, int ultimo){
    //primeiro e último
    //índices do vetor
    int i, j, m, aux;
    i=primeiro; j=ultimo;
    m=v[(i+j)/2];
    do {
        while (v[i] < m) i++;
        while (v[j] > m) j--;
        if (i<=j){
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
        }
    } while (i<=j);
    
    if (primeiro < j) //chamada recursiva da 1ª metade
       quicksort(v,primeiro,j);
    if (ultimo > i) //chamada recursiva da 2ª metade
       quicksort(v,i,ultimo);
} 

void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int vec[], int left, int right) {
    int i, j;
    i = left;
    for (j = left + 1; j <= right; ++j) {
        if (vec[j] < vec[left]) {
            ++i;
            swap(&vec[i], &vec[j]);
        }
    }
    swap(&vec[left], &vec[i]);
    
    return i;
}

void quickSort(int vec[], int left, int right) {
    int r;
    if (right > left) {
        r = partition(vec, left, right);
        quickSort(vec, left, r - 1);
        quickSort(vec, r + 1, right);
    }
}

//###################################################################################################
// mergesort
//###################################################################################################
void intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = (int*)malloc ((r-p) * sizeof (int));
    i = p; j = q;
    k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; ++i) v[i] = w[i-p];
    free (w);
}

void mergesort (int p, int r, int v[]) {
    if (p < r-1) {
        int q = (p + r)/2;
        mergesort (p, q, v);
        mergesort (q, r, v);
        intercala (p, q, r, v);
    }
}

int main()
{
   int Y[] = { 4, 2, -3, 0, 9, 3, 9, 7 }; // definir vetor dados
   char W[] = {'c', 'C','G','a','F','i'};
   int X[] = { -1, -1, -1, -1, -1, -1, -1, -1 };
   int Z[] = { 1, 2, 3, 4, 5, 6};
   //imprimir(Y, 8);
   //algoritmos de ordenacao
   //bubblesort(Y, 8);
   //bubblesortDecrescente(Y, 8);
   //bubblesort(Z, 6);
   //ordena_por_contagem(Y, X, 8);
   //ordena_por_contagemrepetidos(Y, X, 8);
   //selection_sort(Y, 8);
   //insertionSort(Y, 8);
   //quicksortV1(Y, 0, 7);
   bubblesortCaractere(W, 6);
   //quicksortV2(W, 0, 7);
   //imprimir(W, 8);
   
  system("PAUSE");	
  return 0;
}
