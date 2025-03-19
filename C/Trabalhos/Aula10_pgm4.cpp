#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct TDados {
  int A;
  int B;
  double X;
  double Y;
  char C;
};

void ExibeDados(TDados *pDados, int pTam) {
  for (int i = 0; i < pTam; i++) {
    printf("A = %5d  B = %5c  X = %7.2lf  Y = %7.2lf  C = %lf\n",
      pDados[i].A,
      pDados[i].B,
      pDados[i].X,
      pDados[i].Y,
      pDados[i].C);
  }
}
 
int main() {
  FILE *Arq;
  int Tam;
  TDados *Dados; // vetor dinâmico amplo com elementos do tipo struct
  TDados aux;
  
  Tam = 0;
  Dados = NULL;
  Arq = fopen("produtos.txt", "r");
  while (fscanf(Arq, "%d;%c;%lf;%lf;%lf", &aux.A, &aux.B, &aux.X, &aux.Y, &aux.C) != EOF) {
    Tam++;
    Dados = (TDados *)realloc(Dados, sizeof(TDados) * Tam);
    Dados[Tam-1] = aux;
  }
  fclose(Arq);
  
  ExibeDados(Dados, Tam);
     
  printf("\n\nFim do Programa\n");
  system("pause");
  return 0;
}
