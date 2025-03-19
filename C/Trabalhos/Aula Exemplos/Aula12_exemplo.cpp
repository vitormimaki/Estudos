#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void AlteraA(int *pA) {
  *pA = *pA * 2;
  printf("   dentro de Altera A: A = %d\n", *pA);  
}

int main() {
  int A;
  
  A = 19;
  printf("No main(): A = %d  - antes da funcao\n", A);
  
  AlteraA(&A);

  printf("No main(): A = %d  - depois da funcao\n", A);
  

  printf("\n\nFim do Programa\n");
  system("pause");
  return 0;
}






