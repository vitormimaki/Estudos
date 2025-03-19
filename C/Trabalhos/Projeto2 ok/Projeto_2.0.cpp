#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void alunos() {
	printf("\t-------------------- ALUNOS ----------------------\n");
	printf("\t\t     Arthur de Queiroz\n");
	printf("\t\t Jeferson de Jesus Barbosa\n");
	printf("\t\tVitor Aurelio Saccone Mimaki\n");
	printf("\t--------------------------------------------------\n");
}

struct TProdutos{
	int cod; //Código do Produto
	char contr; //Controle das Peças
	double qntpecas; //Quantidade Peças/Peso
	double puni; //Preço Unitário
	double luc; //Margem de Lucro
};

/*
struct TVendaEstado {
	char uf[22];
	double aliq;
};
*/

struct TData {
	int ano;
	int mes;
	int dia;
};

struct TVendas{
	int ano;
	int mes;
	int dia;
	int cod;
	//TVendaEstado estado;
	double qnt; //Quantidade Vendida
	double prec; //Preço De Venda
	double pTotal;
	double media;
};

struct TDadosAgr {  // struct para os dados agregados
    int Cod;
    int TotQtde;
    double TotValor;
    int NOcorr;
    double lucrat;
    double contrib;
};

TDadosAgr *CriarAgr(TVendas pDE, TDadosAgr *pAgr, int *pTamAgr) {
    (*pTamAgr)++;
    pAgr = (TDadosAgr *)realloc(pAgr, sizeof(TDadosAgr) * *pTamAgr);
    pAgr[*pTamAgr-1].Cod = pDE.cod;
    pAgr[*pTamAgr-1].TotQtde = pDE.qnt;
    pAgr[*pTamAgr-1].TotValor = pDE.pTotal;
    pAgr[*pTamAgr-1].NOcorr = 1;
  
    return pAgr;
};

void AtualizaAgr(TVendas pDE, TDadosAgr *Agr, int pIndice) {
    Agr[pIndice].NOcorr++;
    Agr[pIndice].TotQtde = Agr[pIndice].TotQtde + pDE.qnt;
    Agr[pIndice].TotValor = Agr[pIndice].TotValor + pDE.pTotal;
}

int ExisteCod(int pCod, TDadosAgr *Agr, int TamAgr) {
    int i;
    for (i = 0; i < TamAgr; i++) {
    	if (Agr[i].Cod == pCod) {
    		return i;
		}
	}
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

void OrdenaAgrLuc(TDadosAgr *pAgr, int pTamAgr, double pLuc) {
    int i;
    TDadosAgr aux;
    bool Trocou = true;
    while (Trocou) {
	    Trocou = false;
	    for (i = 0; i < pTamAgr-1; i++) {
			if(pAgr[i].lucrat < pAgr[i+1].lucrat) {
	    		aux = pAgr[i];
	    		pAgr[i] = pAgr[i+1];
	    		pAgr[i+1] = aux;
	    		Trocou = true;
			}
	    }
  	}
}

void OrdenaAgrCon(TDadosAgr *pAgr, int pTamAgr) {
    int i;
    TDadosAgr aux;
    bool Trocou = true;
    while (Trocou) {
	    Trocou = false;
	    for (i = 0; i < pTamAgr-1; i++) {
	    	if(pAgr[i].contrib < pAgr[i+1].contrib) {
	    		aux = pAgr[i];
	    		pAgr[i] = pAgr[i+1];
	    		pAgr[i+1] = aux;
	    		Trocou = true;
			}
	    }
  	}
}

int DiaSemana(int dd, int mm, int aa) { 
 	time_t hora;
 	tm *phora;
 	time(&hora);
 	phora = localtime(&hora);
 	phora->tm_year = aa - 1900;
 	phora->tm_mon = mm - 1;
 	phora->tm_mday = dd;
 	mktime(phora);
	return phora->tm_wday;
}

//Função que retorna quantidade de Dias no mês
int diasMes(int pMes) { //Dias em Cada Mês
	switch (pMes) {
		case 1:
			return 31;
		case 2:
			return 28;
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
	}
}

void ExibeProdutos(TProdutos *pProd, int pTam) {
    for (int i = 0; i < pTam; i++) {
        printf("COD = %5d  TIPO = %c  QNT = %7.2lf  PREC/U = %7.2lf  LUCR = %7.2lf\n",
        	pProd[i].cod,
     	 	pProd[i].contr,
     	 	pProd[i].qntpecas,
      		pProd[i].puni,
      		pProd[i].luc);
    }
}

int main() {	
	FILE *Arq;
	srand(time(NULL));
	
	int i, j;
	int TamAgr;
	int TamP;
	int TamV;
  	
  	alunos();
  	
  	TProdutos *Prod;
	TProdutos auxP;
	
	TamP = 0;
	Prod = NULL;
  	
  	Arq = fopen("produtos.txt", "r");
  	
  	while (fscanf(Arq, "%d;%c;%lf;%lf;%lf;", &auxP.cod, &auxP.contr, &auxP.qntpecas, &auxP.puni, &auxP.luc) != EOF) {
    	TamP++;
    	Prod = (TProdutos *)realloc(Prod, sizeof(TProdutos) * TamP);
    	Prod[TamP-1] = auxP;
    }
    
    fclose(Arq);
    
	ExibeProdutos(Prod, TamP);
	
	printf("\nArquivo de Produtos Importado com Sucesso.\n");
	
	system("pause");
	system("cls");
	
	alunos();
	
	TVendas *Ven;
	TVendas auxV;
	
	TamV = 0;
	Ven = NULL;
	
	Arq = fopen("vendas.txt", "r");
	
	while (fscanf(Arq, "%d;%d;%d;%d;%lf;%lf;", &auxV.ano, &auxV.mes, &auxV.dia, &auxV.cod, &auxV.qnt, &auxV.prec) != EOF) { //&auxV.estado.uf, &auxV.estado.aliq) != EOF) {
	    auxV.pTotal = auxV.qnt * auxV.prec;
	    TamV++;
	    Ven = (TVendas *)realloc(Ven, sizeof(TVendas) * TamV);
	    Ven[TamV-1] = auxV;
    }
	
	fclose(Arq);
	
	printf("\nArquivo de Vendas Importado com Sucesso.\n");
	
	int qtdeDias = TamV + 1;
	
	Ven = (TVendas *)realloc(Ven, sizeof(TVendas) * TamV * 2);
	
	TDadosAgr *Agr;
	int ind;
	
    TamAgr = 0;
    Agr = NULL;
    
    //Parte 1 OK
    
    Arq = fopen("totvendas.txt", "w");
    
    double total;
	double media;
    
    j = 0;
    
    fprintf(Arq, "TOTAIS DE VENDAS POR DIA\n");
    fprintf(Arq, "Dia\t\tTotal\t\tMedia/Dia\n");
	do {
		total = Ven[j].prec;
	    for(i = 1 + j; Ven[i].dia == Ven[i-1].dia; i++) {
	    	total += Ven[i].prec;
		}
		Ven[j].media = total/(i-j);
		
		fprintf(Arq, "%02d/%02d/%04d\t%7.2lf\t\t%7.2lf\n", Ven[j].dia, Ven[j].mes, Ven[j].ano, total, Ven[j].media);
		j = i;
		j++;
 	} while (Ven[j].mes != Ven[TamV].mes || Ven[j].ano != Ven[TamV].ano);
    //NÃO MEXER!!!
    
    fprintf(Arq, "\n");
    
    //Parte 2 OK
    fprintf(Arq, "TOTAIS DE VENDAS POR PRODUTO\n");
    fprintf(Arq, "Prod.       VlrTot\t      Qtde   PçMédio    Lucrat.\n");
    
    
    for (i = 0; i < TamV; i++) {
    	ind = ExisteCod(Ven[i].cod , Agr, TamAgr);
    if (ind >= 0)
        AtualizaAgr(Ven[i], Agr, ind);
    else
        Agr = CriarAgr(Ven[i], Agr, &TamAgr);
    }
  
    OrdenaAgr(Agr, TamAgr);
    
    double pcMedio;
    double pcUnit;
    double lucrat;
    
    for (i = 0; i < TamAgr; i++) {
    	pcMedio = (Agr[i].TotValor/Agr[i].TotQtde);
    	for (j = 0; j < TamP; j++) {
    		if(Prod[j].cod == Agr[i].Cod) {
    			pcUnit = Prod[j].puni;
			}
		}
    	Agr[i].lucrat = (pcMedio / pcUnit - 1) * 100;
    	fprintf(Arq, "%d       %7.2lf        %d        %.2lf    %.1lf%%\n", 
				Agr[i].Cod,
				Agr[i].TotValor,
				Agr[i].TotQtde,
				pcMedio,
				Agr[i].lucrat);
    }
    //NÃO MEXER!!!
    
    fprintf(Arq, "\n");
    
    //Parte 3 OK
    
    int qntDiaUtil = 1;
    double totGeral = 0;
    double qtdeProd = 0;
    double medUtil;
    double medProd;
    double lucMed = 0;
    
    for(i = 0; Ven[i].dia != Ven[TamV].dia || Ven[i].mes != Ven[TamV].mes || Ven[i].ano != Ven[TamV].ano; i++) {
		if(DiaSemana(Ven[i].dia, Ven[i].mes, Ven[i].ano) != 0) {
			qntDiaUtil++;
		}
	}
	
	for(i = 0; i < TamV; i++) {
    	totGeral += Ven[i].prec;
    	qtdeProd += Ven[i].qnt;
	}
	
	medUtil = totGeral/qntDiaUtil;
    medProd = totGeral/qtdeProd * 100;
    
    double auxPeso = 0;
    double soma = 0;
    
    for(i = 0; i < TamAgr; i++) {
    	soma += (Agr[i].lucrat * Agr[i].TotQtde);
		auxPeso += Agr[i].TotQtde;
	}
	lucMed = soma/auxPeso;
    //lucMedia = média ponderada da lucratividade de cada produto usando a quantidade vendida como peso
    
    fprintf(Arq, "TOTAL E ESTATÍSTICAS DO PERÍODO\n");
    fprintf(Arq, "Total Geral de Vendas (R$)\t%.2lf\n", totGeral);
    fprintf(Arq, "Quantidade de produtos vendidos\t%.0lf\n", qtdeProd);
    fprintf(Arq, "Média de Vendas por dia útil (R$)\t%.2lf\n", medUtil);
    fprintf(Arq, "Média de Vendas por produto (R$)\t%.2lf\n", medProd);
    fprintf(Arq, "Lucratividade Média\t%.1lf%%\n", lucMed);
    
    //NÃO MEXER!!!
    
    fprintf(Arq, "\n");
    
    //Parte 4 OK
    
    fprintf(Arq, "PRODUTOS MAIS LUCRATIVOS\n");
    fprintf(Arq, "Lucratividade média = %.1lf%%\n\n", lucMed);
    fprintf(Arq, "Prod.\tLucrat.\n");
    
    OrdenaAgrLuc(Agr, TamAgr, lucMed);
    
    for(i = 0; i < TamAgr, Agr[i].lucrat > lucMed; i++) {
    	fprintf(Arq, "%d\t%.1lf%%\n", Agr[i].Cod, Agr[i].lucrat);
	}
    //NÃO MEXER!!!
    
    fprintf(Arq, "\n");
    
    //Parte 5 OK
    	
    for(i = 0; i < TamAgr; i++) {
    	Agr[i].contrib = 0;
		Agr[i].TotValor = 0;
	}
    	
    for(i = 0; i < TamAgr; i++) {
    	for(j = 0; j < TamV; j++) {
    		if(Ven[j].cod == Agr[i].Cod) {
    			Agr[i].TotValor += Ven[j].prec;
    			Agr[i].contrib += (Ven[j].prec/totGeral) * 100;
			}
		}
	}
    
	/*	
    for(i = 0; i < TamAgr; i++) {
    	Agr[i].contrib = (Agr[i].TotValor/totGeral) * 100;
	}
	*/
    
    OrdenaAgrCon(Agr, TamAgr);
    
    fprintf(Arq, "CONTRIBUIÇÃO DE CADA PRODUTO\n");
    fprintf(Arq, "Prod.\t   VlrTot\tContrib.\n");
    
    for(i = 0; i < TamAgr; i++) {
    	fprintf(Arq, "%d\t%7.2lf\t%.1lf%%\n", Agr[i].Cod, Agr[i].TotValor, Agr[i].contrib);
	}
   
   //NÃO MEXER!!!
    
    fclose(Arq);
  
    printf("\n\nFim do Programa\n");
    system("pause");

	return 0;
}
