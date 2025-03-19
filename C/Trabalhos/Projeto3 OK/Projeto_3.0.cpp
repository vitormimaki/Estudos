#include <stdlib.h>
#include <stdio.h>

void alunos() {
	printf("\t-------------------- ALUNOS ----------------------\n");
	printf("\t\t     Arthur de Queiroz\n");
	printf("\t\t Jeferson de Jesus Barbosa\n");
	printf("\t\tVitor Aurelio Saccone Mimaki\n");
	printf("\t--------------------------------------------------\n");
}

struct TVendas {
	int cod;
	int qtdV;
	int sit;
	int can;
};

struct TProdutos {
	int cod;
	int qtdE;
	int qtdM;
	TVendas info;
	int qtVen;
	int posVen;
	int necess;
	int transf;
};

int main() {
	
	FILE *Arq;
	
	int i, j;
	
	alunos();
	
	//Leitura do Arquivo de Entrada

	TProdutos *Prod;
	TProdutos auxP;
	
	int TamP = 0;
	Prod = NULL;
  	Arq = fopen("produtos.txt", "r");
  	//Arq = fopen("c2_produtos.txt", "r");
  	
  	while (fscanf(Arq, "%d;%d;%d", &auxP.cod, &auxP.qtdE, &auxP.qtdM) != EOF) {
    	TamP++;
    	Prod = (TProdutos *)realloc(Prod, sizeof(TProdutos) * TamP);
    	Prod[TamP-1] = auxP;
    	Prod[TamP-1].necess = 0;
    	Prod[TamP-1].qtVen = 0;
    	Prod[TamP-1].transf = 0;
    	Prod[TamP-1].posVen = 0;
    }
    
    fclose(Arq);
    
    //Leitura do Arquivo de Entrada

	TVendas *Ven;
	TVendas auxV;
	
	int TamV = 0;
	Ven = NULL;
  	Arq = fopen("vendas.txt", "r");
  	//Arq = fopen("c2_vendas.txt", "r");
  	
  	while (fscanf(Arq, "%d;%d;%d;%d", &auxV.cod, &auxV.qtdV, &auxV.sit, &auxV.can) != EOF) {
    	TamV++;
    	Ven = (TVendas *)realloc(Ven, sizeof(TVendas) * TamV);
    	Ven[TamV-1] = auxV;
    }
    
    fclose(Arq);
	
	//PARTE 1 OK
	
	int QtdVendas;
	
	for(i = 0; i < TamP; i++) { //Para cada produto
		QtdVendas = 0;
		for(j = 0; j < TamV; j++) { //Para cada venda
			if(Ven[j].cod == Prod[i].cod) { //Encontre Produto Correspondente a Venda
				Prod[i].info = Ven[j];
				if(Ven[j].sit == 100 || Ven[j].sit == 102) {
					QtdVendas += Ven[j].qtdV;
				}
			}
		}
		Prod[i].qtVen = QtdVendas;
		Prod[i].posVen = Prod[i].qtdE - Prod[i].qtVen;
		if(Prod[i].posVen < Prod[i].qtdM) {
			Prod[i].necess = Prod[i].qtdM - Prod[i].posVen;	
		}
		if(Prod[i].necess > 1 && Prod[i].necess < 10) {
			Prod[i].transf = 10;
		} else {
			Prod[i].transf = Prod[i].necess;
		}
	}
	
	Arq = fopen("transfere.txt", "w");
	
	fprintf(Arq, "Necessidade de Transferência Armazém para CO\n\n");
	fprintf(Arq, "Produto  QtCO  QtMin  QtVendas  Estq.apos  Necess.  Transf. de\n");
	fprintf(Arq, "\t\t\t\tVendas\t\t    Arm p/ CO\n");
	for(i = 0; i < TamP; i++) {
		fprintf(Arq, "%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
					Prod[i].cod,
					Prod[i].qtdE,
					Prod[i].qtdM,
					Prod[i].qtVen,
					Prod[i].posVen,
					Prod[i].necess,
					Prod[i].transf);
	}
	
	fclose(Arq);
	
	//PARTE 2 OK
	
	int linha;
	int cod;
	int existe = 1;

	Arq = fopen("divergencias.txt", "w");
	
	for(j = 0; j < TamV; j++) { //Para cada venda
		if(Ven[j].sit == 135) {
			linha = j + 1;
			fprintf(Arq, "Linha %d – Venda cancelada\n", linha);
		}
		if(Ven[j].sit == 190) {
			linha = j + 1;
			fprintf(Arq, "Linha %d – Venda não finalizada\n", linha);
		}
		if(Ven[j].sit == 999) {
			linha = j + 1;
			fprintf(Arq, "Linha %d – Erro desconhecido. Acionar equipe de TI.\n", linha);
		}
		for(i = 0; i < TamP && existe != 0; i++) {
			if(Ven[j].cod == Prod[i].cod) { //Existe se encontrar
				existe = 0;
			} else {
				linha = j + 1;
				cod = Ven[j].cod;
				existe = 1;
			}
		}
		if(existe == 1) { //Se não existe o cód, armazena as informações
			fprintf(Arq, "Linha %d – Código de Produto não encontrado %d\n", linha, cod);
		}
		existe = 1;
	}
	
	fclose(Arq);
	
	//PARTE 3 OK
	
	Arq = fopen("totcanais.txt", "w");
	
	int totRep = 0;
	int totWeb = 0;
	int totAnd = 0;
	int totIph = 0;
	
	for(i = 0; i < TamV; i++) {
		if(Ven[i].sit == 100 || Ven[i].sit == 102) {
			if(Ven[i].can == 1) {
				totRep += Ven[i].qtdV;
			} else if (Ven[i].can == 2) {
				totWeb += Ven[i].qtdV;
			} else if (Ven[i].can == 3) {
				totAnd += Ven[i].qtdV;
			} else if (Ven[i].can == 4) {
				totIph += Ven[i].qtdV;
			}
		}
	}
	
	fprintf(Arq, "Quantidades de Vendas por canal\n\n");
	fprintf(Arq, "Canal                  QtVendas\n");
	fprintf(Arq, "1 - Representantes\t%d\n", totRep);
	fprintf(Arq, "2 - Website\t%d\n", totWeb);
	fprintf(Arq, "3 - App móvel Android\t%d\n", totAnd);
	fprintf(Arq, "4 - App móvel iPhone\t%d\n", totIph);
	
	fclose(Arq);
	
	return 0;
}
