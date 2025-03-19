//pilha com vetor
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int contaPilha(Pilha *p){
	Pilha *aux=pilha_cria();
	float x;
	int cont=0;
	//esvazia a pilha original para contar
	while(pilha_vazia(p)==0){
		x=pilha_pop(p);
		pilha_push(aux,x);
		cont++;
	}
	//restaura a pilha original a partir da auxiliar
	while(pilha_vazia(aux)==0){
		x=pilha_pop(aux);
		pilha_push(p,x);
	}
	pilha_libera(aux);
	return cont;
}

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha (push)\n");
     printf("2. Retira (pop)\n");
     printf("3. Mostra a pilha\n");
     printf("4. Conta Elementos\n");//int contaPilha(Pilha *p)
     printf("9. Fim\n");
}

main(){
      Pilha *pi=pilha_cria();
      int opmenu;
      float item;
      do{
         menu();
         scanf("%d", &opmenu);
         switch (opmenu){
         case 1 : //insere
                printf("Digite o valor a ser empilhado: ");
                scanf("%f", &item);
                pilha_push(pi,item);
                break;
        case 2 : //retira
               if(pilha_vazia(pi))//verifica antes se está vazia
                   printf("Pilha vazia.\n");
               else
                   printf("Elemento retirado = %.0f\n",pilha_pop(pi));
               break;
        case 3 : //mostra
				if(pilha_vazia(pi))//verifica antes se está vazia
                   printf("Pilha vazia.\n");
                else
                	pilha_mostra(pi);
                break;
        case 4://conta elementos
        		printf("Numero de elementos: %d\n", contaPilha(pi));
        		break;
        
       }//switch
       printf("\n");
       system("pause");
       
     } while(opmenu!=9);
     pilha_libera(pi);
}

