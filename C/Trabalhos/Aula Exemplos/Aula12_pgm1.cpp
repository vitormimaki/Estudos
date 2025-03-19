#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct TDadosEnt {  // struct para os dados de entrada
  int Cod;
  int Qtde;
  double PcUnit;
  double PcTotal;
};

struct TDadosAgr {  // struct para os dados agregados
  int Cod;
  int TotQtde;
  double TotValor;
  int NOcorr;
};

TDadosAgr *CriarAgr(TDadosEnt pDE, TDadosAgr *pAgr, int *pTamAgr) {
  (*pTamAgr)++;
  pAgr = (TDadosAgr *)realloc(pAgr, sizeof(TDadosAgr) * *pTamAgr);
  pAgr[*pTamAgr-1].Cod = pDE.Cod;
  pAgr[*pTamAgr-1].TotQtde = pDE.Qtde;
  pAgr[*pTamAgr-1].TotValor = pDE.PcTotal;
  pAgr[*pTamAgr-1].NOcorr = 1;
  
  return pAgr;
}

void AtualizaAgr(TDadosEnt pDE, TDadosAgr *Agr, int pIndice) {
  Agr[pIndice].NOcorr++;
  Agr[pIndice].TotQtde = Agr[pIndice].TotQtde + pDE.Qtde;
  Agr[pIndice].TotValor = Agr[pIndice].TotValor + pDE.PcTotal;
}

int ExisteCod(int pCod, TDadosAgr *Agr, int TamAgr) {
  int i;
  for (i = 0; i < TamAgr; i++) 
    if (Agr[i].Cod == pCod)
      return i;
  return -1;
}

void OrdenaAgr(TDadosAgr *pAgr, int pTamAgr) {
  int i;
  TDadosAgr aux;
  bool Trocou = true;
  while (Trocou) {
    Trocou = false;
    for (i = 0; i < pTamAgr-1; i++) {
      if (pAgr[i].Cod > pAgr[i+1].Cod) {
        aux = pAgr[i];
        pAgr[i] = pAgr[i+1];
        pAgr[i+1] = aux;
        Trocou = true;
      }
    }
  }
}


int main() {
  int i;
  FILE *ArqDE;
  TDadosEnt *DE; // vetor de dados de entrada - cada elemento deste vetor é um struct TDadosEnt
  TDadosEnt auxDE;
  int TamDE;
  char dummy[5];
  int ind;
  TDadosAgr *Agr; // vetor de dados agregados
  int TamAgr;
  char NomeArq[100];
  
  printf("Digite o nome do arquivo de entrada: ");
  scanf("%s", &NomeArq);
  
  TamDE = 0;
  DE = NULL;
  ArqDE = fopen(NomeArq, "r");
  if (ArqDE == NULL) {
    printf("Erro: arquivo inexistente");
    return 0;
  }
  
  fscanf(ArqDE, "%s", &dummy);
  while (fscanf(ArqDE, "%d;%d;%lf", &auxDE.Cod, &auxDE.Qtde, &auxDE.PcUnit) != EOF) {
    auxDE.PcTotal = auxDE.Qtde * auxDE.PcUnit;
    TamDE++;
    DE = (TDadosEnt *)realloc(DE, sizeof(TDadosEnt) * TamDE);
    DE[TamDE-1] = auxDE;
  }
  fclose(ArqDE);
  for (i = 0; i < TamDE; i++)
    printf("%d: q=%d x pu=%.2lf = %.2lf\n", DE[i].Cod, DE[i].Qtde, DE[i].PcUnit, DE[i].PcTotal);

  TamAgr = 0;
  Agr = NULL;
  for (i = 0; i < TamDE; i++) {
    ind = ExisteCod(DE[i].Cod , Agr, TamAgr);
    if (ind >= 0) 
      AtualizaAgr(DE[i], Agr, ind);
    else
      Agr = CriarAgr(DE[i], Agr, &TamAgr);
  }
  
  OrdenaAgr(Agr, TamAgr);
  printf("\n\nDados Agregados\n");
  for (i = 0; i < TamAgr; i++) {
    printf("elemento %d: Cod = %d\n", i, Agr[i].Cod);
    printf("    NOcorr = %d\n", Agr[i].NOcorr);
    printf("    Qtde   = %d\n", Agr[i].TotQtde);
    printf("    Valor  = %.2lf\n", Agr[i].TotValor);
  }
  
  printf("\n\nFim do Programa\n");
  system("pause");
  return 0;
}






