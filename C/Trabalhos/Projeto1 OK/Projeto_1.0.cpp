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

struct TVendaEstado {
	char uf[22];
	double aliq;
};

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
	TVendaEstado estado;
	double qnt; //Quantidade Vendida
	double prec; //Preço De Venda
};

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

TVendaEstado SorteiaEstados() {
	int sort;
	TVendaEstado estados[4];
	
	strcpy(estados[0].uf, "Sao Paulo");
	estados[0].aliq = 0.18;
	strcpy(estados[1].uf, "Sudeste e Sul");
	estados[1].aliq = 0.12;
	strcpy(estados[2].uf, "Zona Franca de Manaus");
	estados[2].aliq = 0;
	strcpy(estados[3].uf, "Demais UFs");
	estados[3].aliq = 0.07;
	
	sort = rand() % 4;
	
	return estados[sort];
	
}

// Função para gerar um valor de venda com variação
double gerarPrecoDeVenda(double precoCusto, double margemLucro) {
    double variacao = ((rand() % 17) - 8) / 100.0; // Variação entre -8% e +8%
    return precoCusto * (1.0 + margemLucro + variacao);
}

//Função para exibir Produtos
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
	
	alunos();
	
	//Leitura do Arquivo de Entrada

	TProdutos *Prod;
	TProdutos aux;
	
	int Tam = 0;
	Prod = NULL;
  	Arq = fopen("produtos.txt", "r");
  	
  	while (fscanf(Arq, "%d;%c;%lf;%lf;%lf;", &aux.cod, &aux.contr, &aux.qntpecas, &aux.puni, &aux.luc) != EOF) {
    	Tam++;
    	Prod = (TProdutos *)realloc(Prod, sizeof(TProdutos) * Tam);
    	Prod[Tam-1] = aux;
    }
    
	ExibeProdutos(Prod, Tam);

	fclose(Arq);
	system("pause");
	system("cls");
	
	//Registro Do Arquivo de Vendas
	
	alunos();
	
	int diaI, mesI, anoI;
	int diaK, mesK, anoK;
	int diaT, mesT, anoT;
	int QtdeVendasDia;
	int NDiasMes;

	do {
		printf("Digite o Ano de Inicio Desejado: ");
		//anoI = rand() % 8 + 2016;
		//printf(" %d\n", anoI);
		scanf("%d", &anoI);
		if(anoI < 2016 || anoI > 2023) {
			printf("Inserir um valor no Intervalo [2016,2023]\n");
		}
	} while (anoI < 2016 || anoI > 2023);
		
	do {
		printf("Digite o Mes de Inicio Desejado: ");
		//mesI = rand() % 13 + 1;
		//printf(" %d\n", mesI);
		scanf("%d", &mesI);
		if(mesI < 1 || mesI > 12) {
			printf("Inserir um valor no Intervalo [1,12]\n");
		}
	} while (mesI < 1 || mesI > 12);
	
	NDiasMes = diasMes(mesI);
	
	do {
		printf("Digite o Dia de Inicio Desejado: ");
		//diaI = rand() % (NDiasMes + 1) + 1;
		//printf(" %d\n", diaI);
		scanf("%d", &diaI);
		if(diaI < 1 || diaI > NDiasMes) {
			printf("Inserir um valor no Intervalo [1,%d]\n", NDiasMes);
		}
	} while (diaI < 1 || diaI > NDiasMes);
	
	printf("----------------------------------------------\n");
	
	do {
		printf("Digite o Ano de Termino Desejado: ");
		//anoT = rand() % 8 + 2016;
		//printf(" %d\n", anoT);
		scanf("%d", &anoT);
		if(anoT < anoI || anoT > 2023) {
			printf("Inserir um valor no Intervalo [%d,2023]\n", anoI);
		}
	} while (anoT < anoI || anoT > 2023);
	
	int auxMes;
	
	if (anoT == anoI) {
		auxMes = mesI;
	} else {
		auxMes = 1;
	}
	
	do {
		printf("Digite o Mes de Termino Desejado: ");
		//mesT = rand() % 13 + 1;
		//printf(" %d\n", mesT);
		scanf("%d", &mesT);
		if(mesT < auxMes || mesT > 12) {
			printf("Inserir um valor no Intervalo [%d,12]\n", auxMes);
		}
	} while (mesT < auxMes || mesT > 12);
	
	NDiasMes = diasMes(mesT);
	
	int auxDia;
	
	if (anoT == anoI && mesT == mesI) {
		auxDia = diaI + 1;
	} else {
		auxDia = 1;
	}
	
	do {
		printf("Digite o Dia de Termino Desejado: ");
		//diaT = rand() % (NDiasMes + 1) + 1;
		//printf(" %d\n", diaT);
		scanf("%d", &diaT);
		if(diaT < auxDia || diaT > NDiasMes) {
			printf("Inserir um valor no Intervalo [%d,%d]\n", auxDia, NDiasMes);
		}
	} while (diaT < auxDia || diaT > NDiasMes);	
	
	printf("Insira a Quantidade de Vendas Diarias: ");
	//QtdeVendasDia = rand() % 11 + 1; //Máx de 10 vendas no dia
	//printf(" %d\n", QtdeVendasDia);
	do {
		scanf("%d", &QtdeVendasDia);
		if(QtdeVendasDia <= 0) {
			printf("O valor deve ser no mínimo 1");
		}
	} while (QtdeVendasDia <= 0);
	
	diaK = diaI;
	mesK = mesI;
	anoK = anoI;
	
	int contaDias = 0;

	while(diaK != diaT || mesK != mesT || anoK != anoT) {
		contaDias++;
		if(diaK == diasMes(mesK)) {
	    	diaK = 0;
	    	mesK++;
		}
		if(mesK == 13) {
			mesK = 1;
			anoK++;
		}
		diaK++;
	}
	
	printf("Contagem Terminada\n");
	
	diaK = diaI;
	mesK = mesI;
	anoK = anoI;

	TVendas Vendas[contaDias+1][QtdeVendasDia];
	
	//Criar Rotina de Atribuição dos Valores de Vendas
	int sort;
	
	for(i = 0; i <= contaDias; i++, diaK++) {
		for(j = 0; j < QtdeVendasDia; j++) {
			if(DiaSemana(diaK, mesK, anoK) != 0) { //Se Não For Domingo
				sort = rand() % 16; // Escolhe aleatoriamente um produto
				Vendas[i][j].ano = anoK;
		        Vendas[i][j].mes = mesK;
		        Vendas[i][j].dia = diaK;
		        Vendas[i][j].cod = Prod[sort].cod;
		        Vendas[i][j].estado = SorteiaEstados();
		        if (Prod[sort].contr == 85) { //"P" = 80; "U" = 85
		        	Vendas[i][j].qnt = ((rand() % (int)Prod[sort].qntpecas) + 1); //Venda Por Unidade
				} else {
					Vendas[i][j].qnt = (rand() % (int)(Prod[sort].qntpecas * 1000))/1000.0 ; //Venda por Peso
				}
		        if ((double)rand() / RAND_MAX <= 0.35) {
		        	Vendas[i][j].prec = gerarPrecoDeVenda(Prod[sort].puni, Prod[sort].luc);
				} else {
					Vendas[i][j].prec = Prod[sort].puni * (1.0 + Prod[sort].luc);
				}
			}
		}
		if(diaK == diasMes(mesK)) {
	    	diaK = 0;
	    	mesK++;
		}
		if(mesK == 13) {
			mesK = 1;
			anoK++;
		}
    }
    
    printf("Atribuicao Bem-Sucedida!\n");
    
    diaK = diaI;
	mesK = mesI;
	anoK = anoI;
    
    //Registro em Txt
	
  	Arq = fopen("vendas.txt", "w");
  	
	for (i = 0; i <= contaDias; i++, diaK++) {
		for(j = 0; j < QtdeVendasDia; j++) {
			if(DiaSemana(diaK, mesK, anoK) != 0) { //Se Não For Domingo
				fprintf(Arq, "%04d;%02d;%02d;%05d;%.3lf;%.2lf;\n", //%s;%.2lf;\n",
					Vendas[i][j].ano,
					Vendas[i][j].mes,
					Vendas[i][j].dia,
					Vendas[i][j].cod,
					Vendas[i][j].qnt,
					Vendas[i][j].prec);//,
					//Vendas[i][j].estado.uf,
					//Vendas[i][j].estado.aliq);
			}
		}
		if(diaK == diasMes(mesK)) {
	    	diaK = 0;
	    	mesK++;
		}
		if(mesK == 13) {
			mesK = 1;
			anoK++;
		}
	}
		
	fclose(Arq);
	
	printf("Fim do Programa.\n");
	
	system("pause");
	
	return 0;
}
